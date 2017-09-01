# $NetBSD: u-boot-arm64.mk,v 1.1 2017/09/01 21:03:11 jmcneill Exp $

MAINTAINER=	port-arm@NetBSD.org
BUILD_DEPENDS+=	cross-aarch64-none-elf-gcc-[0-9]*:../../cross/aarch64-none-elf-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-aarch64-none-elf/bin/aarch64-none-elf-

.include "u-boot.mk"
