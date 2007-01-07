# $NetBSD: Makefile,v 1.7 2007/01/07 09:13:48 rillig Exp $

DISTNAME=	nttcp-1.47
PKGREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	http://home.leo.org/~elmar/nttcp/

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://home.leo.org/~elmar/nttcp/
COMMENT=	New TCP testing and performance measuring tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LIB="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} nttcp ${PREFIX}/bin/nttcp ; \
	${INSTALL_MAN} nttcp.1 ${PREFIX}/${PKGMANDIR}/man1/nttcp.1

.include "../../mk/bsd.pkg.mk"
