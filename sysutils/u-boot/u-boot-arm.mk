# $NetBSD: u-boot-arm.mk,v 1.4 2023/06/06 12:42:23 riastradh Exp $

MAINTAINER=	port-arm@NetBSD.org
TOOL_DEPENDS+=	cross-arm-none-eabi-gcc-[0-9]*:../../cross/arm-none-eabi-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-arm-none-eabi/bin/arm-none-eabi-

.include "u-boot.mk"
