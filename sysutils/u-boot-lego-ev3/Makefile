# $NetBSD: Makefile,v 1.1 2026/09/10 20:03:41 yurix Exp $

UBOOT_TARGET=	lego-ev3
UBOOT_CONFIG=	legoev3_defconfig
UBOOT_BIN=	u-boot.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist
UBOOT_VERSION=		2024.10

# include u-boot first so it can set PATCHDIR
.include "../../sysutils/u-boot/u-boot-arm.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
BUILDLINK_DEPMETHOD.openssl?=build
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
