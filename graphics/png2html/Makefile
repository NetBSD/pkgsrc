# $NetBSD: Makefile,v 1.14 2005/02/21 20:26:11 hubertf Exp $
#

DISTNAME=	png2html-1.1
PKGREVISION=	4
CATEGORIES=	graphics www
MASTER_SITES=	http://www.engr.mun.ca/~holden/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.engr.mun.ca/~holden/png2html.html
COMMENT=	Takes a PNG image and transforms it to a web page

USE_BUILDLINK3=	YES
FIX_RPATH+=	CFLAGS
CFLAGS+=	-L${BUILDLINK_PREFIX.gd}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gd}/lib

do-install:
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/png2html
		${INSTALL_PROGRAM} ${WRKSRC}/png2html ${PREFIX}/bin

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
