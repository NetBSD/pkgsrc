# $NetBSD: Makefile,v 1.10 2004/04/25 12:07:12 dillo Exp $
#

DISTNAME=	manual-1.8.1-2
PKGNAME=	freeciv-manual-1.8.1.2
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/contrib/manual/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freeciv.org/
COMMENT=	Manuals for freeciv (game, client, and server)

WRKSRC=		${WRKDIR}/manual
USE_BUILDLINK3=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/freeciv/img
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.html ${PREFIX}/share/doc/html/freeciv
	cd ${WRKSRC}/img && \
	${INSTALL_DATA} *.jpg ${PREFIX}/share/doc/html/freeciv/img

.include "../../mk/bsd.pkg.mk"
