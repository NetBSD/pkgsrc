# $NetBSD: Makefile,v 1.4 2001/02/25 04:17:49 hubertf Exp $
#

DISTNAME=	manual-1.8.1-2
PKGNAME=	freeciv-manual-1.8.1.2
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/contrib/manual/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.freeciv.org/
COMMENT=	manuals for freeciv (game, client, and server)

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/manual

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/freeciv/img
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.html ${PREFIX}/share/doc/html/freeciv
	cd ${WRKSRC}/img && \
	${INSTALL_DATA} *.jpg ${PREFIX}/share/doc/html/freeciv/img

.include "../../mk/bsd.pkg.mk"
