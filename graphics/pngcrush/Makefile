# $NetBSD: Makefile,v 1.79 2014/02/01 11:54:50 adam Exp $

DISTNAME=	pngcrush-1.7.70-nolib
PKGNAME=	${DISTNAME:C/-nolib//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmt/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pmt.sourceforge.net/pngcrush/index.html
COMMENT=	Optimizer for PNG (Portable Network Graphics) files
LICENSE=	zlib

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} -DPNG_USE_LOCAL_ARRAYS \
		${CFLAGS} `libpng-config --cflags` -o pngcrush pngcrush.c \
		${LDFLAGS} `libpng-config --ldflags` -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${DESTDIR}${PREFIX}/bin

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
