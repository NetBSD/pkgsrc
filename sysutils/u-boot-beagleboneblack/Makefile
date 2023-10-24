# $NetBSD: Makefile,v 1.10 2023/10/24 22:11:15 wiz Exp $

UBOOT_TARGET=		beagleboneblack
UBOOT_CONFIG=		am335x_evm_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+=		MLO

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_VERSION=		2022.04

PKGREVISION= 1
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
