# $NetBSD: Makefile,v 1.14 2012/10/06 11:54:38 asau Exp $
#

DISTNAME=	manual-1.8.1-2
PKGNAME=	freeciv-manual-1.8.1.2
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/contrib/manual/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freeciv.org/
COMMENT=	Manuals for freeciv (game, client, and server)

WRKSRC=		${WRKDIR}/manual
NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/freeciv/img
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.html ${DESTDIR}${PREFIX}/share/doc/html/freeciv
	cd ${WRKSRC}/img && \
	${INSTALL_DATA} *.jpg ${DESTDIR}${PREFIX}/share/doc/html/freeciv/img

.include "../../mk/bsd.pkg.mk"
