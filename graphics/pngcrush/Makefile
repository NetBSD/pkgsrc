# $NetBSD: Makefile,v 1.93 2024/02/01 09:15:09 wiz Exp $

DISTNAME=	pngcrush-1.8.13-nolib
PKGNAME=	${DISTNAME:S/-nolib//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmt/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pmt.sourceforge.io/pngcrush/index.html
COMMENT=	Optimizer for PNG (Portable Network Graphics) files
LICENSE=	zlib

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin

CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600

do-build:
	cd ${WRKSRC} && ${CC} -DPNG_USE_LOCAL_ARRAYS \
		${CFLAGS} `libpng-config --cflags` -o pngcrush pngcrush.c \
		${LDFLAGS} `libpng-config --ldflags` -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${DESTDIR}${PREFIX}/bin

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
