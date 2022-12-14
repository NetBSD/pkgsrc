# $NetBSD: Makefile,v 1.5 2022/12/14 14:33:24 fcambus Exp $

DISTNAME=	pngcheck-3.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.libpng.org/pub/png/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libpng.org/pub/png/apps/pngcheck.html
COMMENT=	Verify the integrity of PNG, JNG, and MNG files
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin share/doc/pngcheck

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} ${LIBS} -DUSE_ZLIB \
		-o pngcheck pngcheck.c -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pngcheck

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
