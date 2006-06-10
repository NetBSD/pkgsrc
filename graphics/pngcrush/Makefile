# $NetBSD: Makefile,v 1.24 2006/06/10 07:43:11 adam Exp $

DISTNAME=	pngcrush-1.6.4-nolib
PKGNAME=	pngcrush-1.6.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://pmt.sourceforge.net/pngcrush/index.html
COMMENT=	Optimizer for PNG (Portable Network Graphics) files

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} -DPNG_USE_LOCAL_ARRAYS \
		${CFLAGS} `libpng-config --cflags` -o pngcrush pngcrush.c \
		`libpng-config --ldflags`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
