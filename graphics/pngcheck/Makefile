# $NetBSD: Makefile,v 1.2 2008/03/04 15:39:10 jlam Exp $
#

DISTNAME=	pngcheck-2.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=png-mng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/apps/pngcheck.html
COMMENT=	Verify the integrity of PNG, JNG, and MNG files

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} ${LIBS} -DUSE_ZLIB \
		-o pngcheck pngcheck.c -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pngcheck
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pngcheck

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
