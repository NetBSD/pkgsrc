# $NetBSD: Makefile,v 1.1 2024/06/17 11:25:15 skrll Exp $

OPENSBI_BOARD=		visionfive2
OPENSBI_PLATFORM=	generic

MAKE_ENV+=		FW_TEXT_START=0x40000000 FW_OPTIONS=0

OPENSBI_BIN=		fw_dynamic.bin

.include "../../sysutils/opensbi/opensbi.mk"
.include "../../mk/bsd.pkg.mk"
