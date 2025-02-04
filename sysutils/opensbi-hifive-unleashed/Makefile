# $NetBSD: Makefile,v 1.1 2025/02/04 02:16:46 gutteridge Exp $

OPENSBI_BOARD=		hifive-unleashed
OPENSBI_PLATFORM=	generic

MAKE_ENV+=		FW_TEXT_START=0x40000000 FW_OPTIONS=0

OPENSBI_BIN=		fw_dynamic.bin

.include "../../sysutils/opensbi/opensbi.mk"
.include "../../mk/bsd.pkg.mk"
