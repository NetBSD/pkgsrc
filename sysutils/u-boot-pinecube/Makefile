# $NetBSD: Makefile,v 1.1 2022/07/29 13:49:41 thorpej Exp $

UBOOT_TARGET=		pinecube
UBOOT_CONFIG=		pinecube_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_VERSION=		2022.04

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
