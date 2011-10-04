# $NetBSD: Makefile,v 1.48.2.1 2011/10/04 23:11:40 tron Exp $

DISTNAME=	pngcrush-1.7.17
PKGNAME=	${DISTNAME:C/-nolib//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://pmt.sourceforge.net/pngcrush/index.html
COMMENT=	Optimizer for PNG (Portable Network Graphics) files
LICENSE=	png-license

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin

#do-build:
#	cd ${WRKSRC} && ${CC} -DPNG_USE_LOCAL_ARRAYS \
#		${CFLAGS} `libpng-config --cflags` -o pngcrush pngcrush.c \
#		${LDFLAGS} `libpng-config --ldflags` -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${DESTDIR}${PREFIX}/bin

#.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
