# $NetBSD: Makefile,v 1.17 2006/02/05 23:09:38 joerg Exp $
#

DISTNAME=	png2html-1.1
PKGREVISION=	5
CATEGORIES=	graphics www
MASTER_SITES=	http://www.engr.mun.ca/~holden/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.engr.mun.ca/~holden/png2html.html
COMMENT=	Takes a PNG image and transforms it to a web page

FIX_RPATH+=	CFLAGS
CFLAGS+=	-L${BUILDLINK_PREFIX.gd}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gd}/lib

INSTALLATION_DIRS=	bin

do-install:
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/png2html
		${INSTALL_MAN} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/png2html
		${INSTALL_PROGRAM} ${WRKSRC}/png2html ${PREFIX}/bin

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
