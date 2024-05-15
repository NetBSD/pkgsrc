# $NetBSD: Makefile,v 1.3 2024/05/15 20:34:16 wiz Exp $

DISTNAME=	libplacebo-v6.338.2
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	multimedia
MASTER_SITES=	https://code.videolan.org/videolan/libplacebo/-/archive/v${PKGVERSION_NOREV}/

FAST_FLOAT_H=		fast_float.h
SITES.${FAST_FLOAT_H}=	https://github.com/fastfloat/fast_float/releases/download/v6.0.0/
DISTFILES=		${DEFAULT_DISTFILES} ${FAST_FLOAT_H}

# Needed for fast_float.h that is an unversioned distfile
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.videolan.org/videolan/libplacebo
COMMENT=	GPU-accelerated image/video processing primitives and shaders
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-glad2-[0-9]*:../../graphics/py-glad2

MESON_ARGS+=	-Ddemos=false
MESON_ARGS+=	-Ddovi=disabled
MESON_ARGS+=	-Dglslang=disabled
MESON_ARGS+=	-Dlcms=enabled
MESON_ARGS+=	-Dopengl=enabled
MESON_ARGS+=	-Dshaderc=disabled
# doesn't work
MESON_ARGS+=	-Dvulkan=disabled
MESON_ARGS+=	-Dxxhash=enabled

PYTHON_FOR_BUILD_ONLY=	yes
USE_TOOLS+=		pkg-config

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++20

PKGCONFIG_OVERRIDE+=	output/meson-private/libplacebo.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

# Populate <fast_float/fast_float.h>
pre-configure:
	${MKDIR} ${WRKSRC}/3rdparty/fast_float/include/fast_float
	${MV} ${WRKDIR}/fast_float.h ${WRKSRC}/3rdparty/fast_float/include/fast_float

.include "../../devel/meson/build.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
