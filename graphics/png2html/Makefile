# $NetBSD: Makefile,v 1.5 2002/03/13 17:37:15 fredb Exp $
#

DISTNAME=	png2html-1.1
PKGREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	http://www.engr.mun.ca/~holden/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.engr.mun.ca/~holden/png2html.html
COMMENT=	Takes a PNG image and transforms it to a web page

USE_BUILDLINK_ONLY=	YES
CFLAGS+=	-L${BUILDLINK_DIR}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib -Wl,-R${LOCALBASE}/lib

do-install:
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/png2html
		${INSTALL_PROGRAM} ${WRKSRC}/png2html ${PREFIX}/bin

.include "../../graphics/gd/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
