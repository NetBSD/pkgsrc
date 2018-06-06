# $NetBSD: u-boot-arm.mk,v 1.2 2018/06/06 21:58:28 wiz Exp $

MAINTAINER=	port-arm@NetBSD.org
BUILD_DEPENDS+=	cross-arm-none-eabi-gcc-[0-9]*:../../cross/arm-none-eabi-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-arm-none-eabi/bin/arm-none-eabi-

.include "u-boot.mk"
.include "../../mk/bsd.pkg.mk"
