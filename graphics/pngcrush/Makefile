# $NetBSD: Makefile,v 1.36 2009/08/30 14:03:51 adam Exp $

DISTNAME=	pngcrush-1.7.1-nolib
PKGNAME=	pngcrush-1.7.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://pmt.sourceforge.net/pngcrush/index.html
COMMENT=	Optimizer for PNG (Portable Network Graphics) files

PKG_DESTDIR_SUPPORT=	user-destdir

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
