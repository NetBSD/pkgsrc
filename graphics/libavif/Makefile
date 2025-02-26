# $NetBSD: Makefile,v 1.5 2025/02/26 08:42:03 adam Exp $

DISTNAME=	libavif-1.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AOMediaCodec/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AOMediaCodec/libavif
COMMENT=	AV1 image file format library
LICENSE=	2-clause-bsd

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DAVIF_BUILD_GDK_PIXBUF=ON
CMAKE_CONFIGURE_ARGS+=	-DAVIF_CODEC_AOM=SYSTEM
CMAKE_CONFIGURE_ARGS+=	-DAVIF_ENABLE_WERROR=OFF
CMAKE_CONFIGURE_ARGS+=	-DAVIF_LIBYUV=OFF

PKGCONFIG_OVERRIDE=	libavif.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../graphics/gdk-pixbuf2/loaders.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
