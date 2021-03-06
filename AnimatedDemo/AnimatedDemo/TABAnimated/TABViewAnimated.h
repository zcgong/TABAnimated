//
//  TABViewAnimated.h
//  lifeAndSport
//
//  Created by tigerAndBull on 2018/9/14.
//  Copyright © 2018年 tigerAndBull. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "UIView+Animated.h"

#define tab_kColor(c) [UIColor colorWithRed:((c>>24)&0xFF)/255.0 green:((c>>16)&0xFF)/255.0 blue:((c>>8)&0xFF)/255.0 alpha:((c)&0xFF)/255.0]
#define tab_kBackColor tab_kColor(0xEEEEEEFF)

typedef NS_ENUM(NSInteger,TABAnimationType) {
    TABAnimationTypeOnlySkeleton = 0,    // onlySkeleton for all views in your project.
    TABAnimationTypeBinAnimation,        // default animation for all registered views in your project.
    TABAnimationTypeShimmer              // shimmer animation for all views in your project.
};

@interface TABViewAnimated : NSObject

@property (nonatomic,assign) TABAnimationType animationType;

// Compare to old view's height. Default is 0.75, do not adapt to UIImageView.
@property (nonatomic,assign) CGFloat animatedHeightCoefficient;

@property (nonatomic,assign) CGFloat animatedDurationShimmer;    // TABAnimationTypeShimmer: default is 1.5

@property (nonatomic,strong) UIColor *animatedColor;             // default is 0xEEEEEE. the backgroundcolor of your animations.

// 全局圆角
// 优先级：view设置的圆角 > animatedCornerRadius
@property (nonatomic,assign) CGFloat animatedCornerRadius;

#pragma mark - 模版相关

// 是否开启模版模式，内置默认模版
@property (nonatomic,assign) BOOL isUseTemplate;

// 设置全局模版
@property (nonatomic) Class templateTableViewCell;
@property (nonatomic) Class templateCollectionViewCell;

#pragma mark - Other

// 是否开启控制台Log提醒
@property (nonatomic,assign) BOOL openLog;


/**
 SingleTon

 @return return object
 */
+ (TABViewAnimated *)sharedAnimated;

#pragma mark - OnlySkeleton

- (void)initWithOnlySkeleton;

#pragma mark - Bin Animation

- (void)initWithBinAnimation;

#pragma mark - Shimmer Animation

/**
 shimmer Animation

 */
- (void)initWithShimmerAnimated;

/**
 shimmer Animation
 
 @param duration back and forth
 @param color backgroundcolor
 */
- (void)initWithShimmerAnimatedDuration:(CGFloat)duration
                              withColor:(UIColor *)color;

@end
