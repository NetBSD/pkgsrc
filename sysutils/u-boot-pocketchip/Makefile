# $NetBSD: Makefile,v 1.1 2017/08/27 19:24:55 jmcneill Exp $

UBOOT_TARGET=		pocketchip
UBOOT_CONFIG=		PocketCHIP_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

post-extract:
	cp ${FILESDIR}/${UBOOT_CONFIG} ${WRKSRC}/configs

.include "../../sysutils/u-boot/u-boot-arm.mk"
