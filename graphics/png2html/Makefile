# $NetBSD: Makefile,v 1.25 2011/11/01 06:01:43 sbd Exp $
#

DISTNAME=	png2html-1.1
PKGREVISION=	11
CATEGORIES=	graphics www
MASTER_SITES=	http://www.engr.mun.ca/~holden/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.engr.mun.ca/~holden/png2html.html
COMMENT=	Takes a PNG image and transforms it to a web page

PKG_DESTDIR_SUPPORT=	user-destdir

FIX_RPATH+=	CFLAGS
CFLAGS+=	-L${BUILDLINK_PREFIX.gd}/lib \
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gd}/lib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/share/doc/png2html
	${INSTALL_MAN} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/png2html
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/png2html
	${INSTALL_MAN} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/share/doc/png2html
	${INSTALL_PROGRAM} ${WRKSRC}/png2html ${DESTDIR}${PREFIX}/bin

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
