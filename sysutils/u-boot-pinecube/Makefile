# $NetBSD: Makefile,v 1.3 2023/12/18 21:57:35 gutteridge Exp $

UBOOT_TARGET=		pinecube
UBOOT_CONFIG=		pinecube_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_VERSION=		2022.04

PKGREVISION=	1

# u-boot-arm.mk must be before bsd.prefs.mk so that PATCHDIR is set correctly.
.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
.include "../../security/openssl/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
