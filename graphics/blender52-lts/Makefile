# $NetBSD: Makefile,v 1.2 2026/11/11 11:53:40 wiz Exp $

DISTNAME=	blender-5.2.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://download.blender.org/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.blender.org/
COMMENT=	Fully integrated 3D graphics creation suite
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

USE_TOOLS+=	pkg-config

# GCC 11.0.0 or later is required.
GCC_REQD+=	12

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
# uses alloca() but sets -std=c++20
FORCE_CXX_STD=	gnu++20
.endif

CMAKE_CONFIGURE_ARGS+=	-DWITH_MEM_JEMALLOC=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_PYTHON_INSTALL=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_INSTALL_PORTABLE=OFF

CMAKE_CONFIGURE_ARGS+=	-DWITH_BULLET=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_OPENCOLORIO=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_FFTW3=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_SDL=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_SDL_DYNLOAD=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_CODEC_FFMPEG=ON
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_AVCODEC_LIBRARY=${BUILDLINK_DIR}/lib/ffmpeg8/libavcodec.so
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_AVDEVICE_LIBRARY=${BUILDLINK_DIR}/lib/ffmpeg8/libavdevice.so
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_AVFILTER_LIBRARY=${BUILDLINK_DIR}/lib/ffmpeg8/libavfilter.so
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_AVFORMAT_LIBRARY=${BUILDLINK_DIR}/lib/ffmpeg8/libavformat.so
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_AVUTIL_LIBRARY=${BUILDLINK_DIR}/lib/ffmpeg8/libavutil.so
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_SWSCALE_LIBRARY=${BUILDLINK_DIR}/lib/ffmpeg8/libswscale.so
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_SWRESAMPLE_LIBRARY=${BUILDLINK_DIR}/lib/ffmpeg8/libswresample.so
CMAKE_CONFIGURE_ARGS+=	-D_ffmpeg_INCLUDE_DIR=${BUILDLINK_DIR}/include/ffmpeg8
CMAKE_CONFIGURE_ARGS+=	-DWITH_CODEC_SNDFILE=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_SYSTEM_EIGEN=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_SYSTEM_FREETYPE=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_SYSTEM_GLEW=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_CYCLES_EMBREE=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_POTRACE=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_VULKAN_BACKEND=OFF

CMAKE_CONFIGURE_ARGS+=	-DPYTHON_VERSION=${PYVERSSUFFIX}
CMAKE_CONFIGURE_ARGS+=	-DWITH_PYTHON_INSTALL_NUMPY=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_PYTHON_INSTALL_REQUESTS=OFF

CMAKE_CONFIGURE_ARGS+=	-DMATERIALX_STDLIB_DIR=${PREFIX}/share/materialx/libraries/stdlib

#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=ON

PLIST_SUBST+=	BLENDERVER=${PKGVERSION_NOREV:R}

REPLACE_PYTHON+=	scripts/modules/blend_render_info.py

#PYTHON_VERSIONS_INCOMPATIBLE=	310 311 313 314

.include "options.mk"
.include "../../devel/cmake/build.mk"
# openxr
# openpgl
# rubberband
# nanovdb
# openusd
# hydra
# openimagedenoise
# meshoptimizer
# optix

# wayland-client
# waylanf-egl
# wayland-scanner
# wayland-protocol


#.include "../../archivers/minizip-ng/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
#.include "../../devel/SDL2/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
#.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/openvdb/buildlink3.mk"
#.include "../../devel/pystring/buildlink3.mk"
.include "../../geography/draco/buildlink3.mk"
.include "../../graphics/alembic/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../graphics/glew/buildlink3.mk"
#.include "../../graphics/glu/buildlink3.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
#.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/opencolorio/buildlink3.mk"
#.include "../../graphics/openimageio/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/opensubdiv/buildlink3.mk"
#.include "../../graphics/partio/buildlink3.mk"
#.include "../../graphics/potrace/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/manifold-geometry/buildlink3.mk"
.include "../../graphics/materialx/buildlink3.mk"
.include "../../graphics/osl/buildlink3.mk"
.include "../../math/ceres-solver/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/suitesparse/buildlink3.mk"
.include "../../math/metis/buildlink3.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
#.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../print/libharu/buildlink3.mk"
#.include "../../security/openssl/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/pugixml/buildlink3.mk"
#.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
