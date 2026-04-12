# $NetBSD: Makefile,v 1.62 2026/04/12 18:29:17 wiz Exp $

.include "Makefile.common"

COMMENT=	GIF image format library

CONFLICTS+=	libungif-[0-9]*

INSTALL_TARGET=		install-include
INSTALL_TARGET+=	install-lib

# needs tools
TEST_TARGET=		gifbuild gifecho giffilter gifinto gifsponge giftext giftool gifwedge check
# as of 6.1.3
# 51 tests, 9 failures.

.include "../../mk/bsd.pkg.mk"
