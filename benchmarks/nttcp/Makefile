# $NetBSD: Makefile,v 1.4 2004/07/30 15:50:38 minskim Exp $

DISTNAME=	nttcp-1.47
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.leo.org/~elmar/nttcp/

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.leo.org/~elmar/nttcp/
COMMENT=	New TCP testing and performance measuring tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LIB="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} nttcp ${PREFIX}/bin/nttcp ; \
	${INSTALL_MAN} nttcp.1 ${PREFIX}/man/man1/nttcp.1

.include "../../mk/bsd.pkg.mk"
