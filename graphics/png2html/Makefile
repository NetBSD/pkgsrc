# $NetBSD: Makefile,v 1.7 2003/03/14 19:37:42 jlam Exp $
#

DISTNAME=	png2html-1.1
PKGREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	http://www.engr.mun.ca/~holden/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.engr.mun.ca/~holden/png2html.html
COMMENT=	Takes a PNG image and transforms it to a web page

USE_BUILDLINK2=	YES
FIX_RPATH+=	CFLAGS
CFLAGS+=	-L${BUILDLINK_PREFIX.gd}/lib -Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.gd}/lib

do-install:
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/png2html
		${INSTALL_PROGRAM} ${WRKSRC}/png2html ${PREFIX}/bin

.include "../../graphics/gd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
