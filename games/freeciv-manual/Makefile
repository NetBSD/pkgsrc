# $NetBSD: Makefile,v 1.1.1.1 2000/10/30 14:26:44 wiz Exp $
#

DISTNAME=	manual-1.8.1-2
PKGNAME=	freeciv-manual-1.8.1.2
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/contrib/manual/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.freeciv.org/

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/manual

do-install:
	${MKDIR} ${PREFIX}/share/doc/freeciv/img
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.html ${PREFIX}/share/doc/freeciv
	cd ${WRKSRC}/img && \
	${INSTALL_DATA} *.jpg ${PREFIX}/share/doc/freeciv/img

.include "../../mk/bsd.pkg.mk"
