# $NetBSD: Makefile,v 1.3 2011/03/23 10:56:55 adam Exp $

DISTNAME=	pngcheck-2.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=png-mng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/apps/pngcheck.html
COMMENT=	Verify the integrity of PNG, JNG, and MNG files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin share/doc/pngcheck

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} ${LIBS} -DUSE_ZLIB \
		-o pngcheck pngcheck.c -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pngcheck

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
