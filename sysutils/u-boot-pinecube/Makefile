# $NetBSD: Makefile,v 1.2 2023/10/24 22:11:15 wiz Exp $

UBOOT_TARGET=		pinecube
UBOOT_CONFIG=		pinecube_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_VERSION=		2022.04

PKGREVISION= 1
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
