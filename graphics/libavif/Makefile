# $NetBSD: Makefile,v 1.1 2024/01/05 11:14:02 nros Exp $

DISTNAME=	libavif-1.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AOMediaCodec/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AOMediaCodec/libavif/
COMMENT=	AV1 image file format library
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c99

CMAKE_CONFIGURE_ARGS+=	-DAVIF_CODEC_AOM=SYSTEM
CMAKE_CONFIGURE_ARGS+=	-DAVIF_ENABLE_WERROR=OFF

PKGCONFIG_OVERRIDE=	libavif.pc.cmake

.include "../../devel/cmake/build.mk"

.include "../../multimedia/libaom/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
