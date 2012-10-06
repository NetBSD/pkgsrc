# $NetBSD: Makefile,v 1.4 2012/10/06 14:11:14 asau Exp $

DISTNAME=	pngcheck-2.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=png-mng/}

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
