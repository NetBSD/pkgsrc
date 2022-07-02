# $NetBSD: Makefile,v 1.187 2022/07/02 16:53:22 ryoon Exp $

DISTNAME=	blender-2.93.5
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	https://download.blender.org/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.blender.org/
COMMENT=	Fully integrated 3D graphics creation suite
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c gnu++17

# C++17
GCC_REQD+=	7

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

CMAKE_ARGS+=	-DWITH_MEM_JEMALLOC=OFF
CMAKE_ARGS+=	-DWITH_PYTHON_INSTALL=OFF
CMAKE_ARGS+=	-DWITH_INSTALL_PORTABLE=OFF

CMAKE_ARGS+=	-DWITH_BULLET=OFF
CMAKE_ARGS+=	-DWITH_OPENCOLORIO=ON
CMAKE_ARGS+=	-DWITH_FFTW3=ON
CMAKE_ARGS+=	-DWITH_SDL=ON
CMAKE_ARGS+=	-DWITH_SDL_DYNLOAD=OFF
CMAKE_ARGS+=	-DWITH_CODEC_FFMPEG=ON
CMAKE_ARGS+=	-DWITH_CODEC_SNDFILE=ON
CMAKE_ARGS+=	-DWITH_SYSTEM_GLEW=ON
CMAKE_ARGS+=	-DWITH_CYCLES_EMBREE=OFF

CMAKE_ARGS+=	-DPYTHON_VERSION=${PYVERSSUFFIX}
CMAKE_ARGS+=	-DWITH_PYTHON_INSTALL_NUMPY=OFF
CMAKE_ARGS+=	-DWITH_PYTHON_INSTALL_REQUESTS=OFF

.include "../../graphics/MesaLib/buildlink3.mk"
.if ${MESALIB_SUPPORTS_EGL} == "yes"
#CMAKE_ARGS+=	-DWITH_GL_EGL=ON
.endif

PLIST_SUBST+=	BLENDERVER=${PKGVERSION_NOREV:C/[a-z]//}

REPLACE_PYTHON=		release/bin/blender-thumbnailer.py		\
			release/scripts/addons/io_curve_svg/svg_util_test.py \
			release/scripts/addons/io_scene_fbx/fbx2json.py	\
			release/scripts/addons/io_scene_fbx/json2fbx.py	\
			release/scripts/modules/bl_i18n_utils/merge_po.py \
			release/scripts/modules/blend_render_info.py

INSTALLATION_DIRS=	bin share/blender

PYTHON_VERSIONS_ACCEPTED?=	39

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "options.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/opencolorio/buildlink3.mk"
.include "../../graphics/openimageio/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/potrace/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
