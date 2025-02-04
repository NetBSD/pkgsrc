# $NetBSD: Makefile,v 1.1 2025/02/04 02:22:27 gutteridge Exp $

UBOOT_TARGET=	hifive-unleashed
UBOOT_VERSION=	2024.04
UBOOT_CONFIG=	sifive_unleashed_defconfig
UBOOT_BIN=	spl/u-boot-spl.bin u-boot.itb

post-extract:
	${CP} ${PREFIX}/share/opensbi/hifive-unleashed/fw_dynamic.bin ${WRKSRC}

MAKE_ENV+=	OPENSBI=${WRKSRC}/fw_dynamic.bin

.include "../../sysutils/opensbi-hifive-unleashed/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-riscv64.mk"
.include "../../mk/bsd.pkg.mk"
