# $NetBSD: u-boot-arm.mk,v 1.1 2017/08/12 14:23:43 jmcneill Exp $

MAINTAINER=	port-arm@NetBSD.org
BUILD_DEPENDS+=	cross-arm-none-eabi-gcc-[0-9]*:../../cross/arm-none-eabi-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-arm-none-eabi/bin/arm-none-eabi-

.include "u-boot.mk"
