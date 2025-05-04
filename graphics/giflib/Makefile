# $NetBSD: Makefile,v 1.60 2025/05/04 11:19:19 nia Exp $

.include "Makefile.common"

PKGREVISION=	1

COMMENT=	GIF image format library

CONFLICTS+=	libungif-[0-9]*

# clang: error: no such file or directory: 'dgif_lib.o'
# clang: error: no such file or directory: 'egif_lib.o'
MAKE_JOBS_SAFE=		no

INSTALL_TARGET=		install-include
INSTALL_TARGET+=	install-lib

.include "../../mk/bsd.pkg.mk"
