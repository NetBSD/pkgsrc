# $NetBSD: Makefile,v 1.61 2026/03/10 20:40:57 wiz Exp $

.include "Makefile.common"

COMMENT=	GIF image format library

CONFLICTS+=	libungif-[0-9]*

# clang: error: no such file or directory: 'dgif_lib.o'
# clang: error: no such file or directory: 'egif_lib.o'
#MAKE_JOBS_SAFE=		no

INSTALL_TARGET=		install-include
INSTALL_TARGET+=	install-lib

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
