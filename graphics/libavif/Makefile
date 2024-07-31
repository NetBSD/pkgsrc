# $NetBSD: Makefile,v 1.3 2024/07/31 07:05:38 adam Exp $

DISTNAME=	libavif-1.1.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AOMediaCodec/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AOMediaCodec/libavif
COMMENT=	AV1 image file format library
LICENSE=	2-clause-bsd

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DAVIF_CODEC_AOM=SYSTEM
CMAKE_CONFIGURE_ARGS+=	-DAVIF_ENABLE_WERROR=OFF
CMAKE_CONFIGURE_ARGS+=	-DAVIF_LIBYUV=OFF

PKGCONFIG_OVERRIDE=	libavif.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
