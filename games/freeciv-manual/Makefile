# $NetBSD: Makefile,v 1.7 2003/07/21 16:49:46 martti Exp $
#

DISTNAME=	manual-1.8.1-2
PKGNAME=	freeciv-manual-1.8.1.2
WRKSRC=		${WRKDIR}/manual
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/contrib/manual/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.freeciv.org/
COMMENT=	Manuals for freeciv (game, client, and server)

USE_BUILDLINK2=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/freeciv/img
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.html ${PREFIX}/share/doc/html/freeciv
	cd ${WRKSRC}/img && \
	${INSTALL_DATA} *.jpg ${PREFIX}/share/doc/html/freeciv/img

.include "../../mk/bsd.pkg.mk"
