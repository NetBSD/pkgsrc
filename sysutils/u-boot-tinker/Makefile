# $NetBSD: Makefile,v 1.2 2021/08/12 07:25:59 wiz Exp $

UBOOT_TARGET=		tinker
UBOOT_CONFIG=		tinker-rk3288_defconfig
UBOOT_BIN=		u-boot-tinker-sd.bin

post-build:
	cd ${WRKSRC} && ./tools/mkimage -n rk3288 -T rksd -d ./spl/u-boot-spl-dtb.bin u-boot-tinker-sd.bin
	cd ${WRKSRC} && cat ./u-boot-dtb.bin >> u-boot-tinker-sd.bin

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
