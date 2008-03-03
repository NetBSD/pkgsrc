# $NetBSD: Makefile,v 1.8 2008/03/03 00:51:44 jlam Exp $

DISTNAME=	nttcp-1.47
PKGREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	http://home.leo.org/~elmar/nttcp/

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://home.leo.org/~elmar/nttcp/
COMMENT=	New TCP testing and performance measuring tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LIB="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} nttcp \
		${DESTDIR}${PREFIX}/bin/nttcp
	cd ${WRKSRC} && ${INSTALL_MAN} nttcp.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nttcp.1

.include "../../mk/bsd.pkg.mk"
