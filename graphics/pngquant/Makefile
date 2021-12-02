# $NetBSD: Makefile,v 1.10 2021/12/02 12:35:00 adam Exp $

DISTNAME=	pngquant-2.17.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	http://pngquant.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pngquant.org/
COMMENT=	Command-line utility for lossy compression of PNG images
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

HAS_CONFIGURE=	yes
CONFIG_SHELL=	${TOOLS_PATH.bash}
USE_LANGUAGES=	c c99
USE_TOOLS+=	gmake pkg-config bash

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-libimagequant=${BUILDLINK_PREFIX.libimagequant}
INSTALL_MAKE_FLAGS+=	MANPREFIX=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
