# $NetBSD: Makefile,v 1.157 2025/03/05 06:27:43 adam Exp $

DISTNAME=	hugin-2024.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hugin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hugin.sourceforge.io/
COMMENT=	Panorama photo stitcher
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Image-ExifTool>=8.15:../../graphics/p5-Image-ExifTool

USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config
CONFIGURE_ENV+=		MANDIR=${PKGMANDIR}

CMAKE_CONFIGURE_ARGS+=	-DBUILD_HSI=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_EPOXY=ON

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	src/hugin_script_interface/*.py
REPLACE_PYTHON+=	src/hugin_script_interface/plugins/*.py
REPLACE_PYTHON+=	src/hugin_script_interface/plugins-dev/*.py

SUBST_CLASSES+=		apple
SUBST_MESSAGE.apple=	Avoiding Mac OS X application bundles
SUBST_STAGE.apple=	pre-configure
SUBST_FILES.apple=	src/hugin1/hugin/CMakeLists.txt
SUBST_FILES.apple+=	src/hugin1/calibrate_lens/CMakeLists.txt
SUBST_FILES.apple+=	src/hugin1/icpfind/CMakeLists.txt
SUBST_FILES.apple+=	src/hugin1/ptbatcher/CMakeLists.txt
SUBST_FILES.apple+=	src/hugin1/stitch_project/CMakeLists.txt
SUBST_SED.apple=	-e 's,(APPLE),(ELPPA),g'

# Doesn't define the ZLIB::ZLIB target needed by OpenEXR 3
post-patch:
	rm ${WRKSRC}/CMakeModules/FindZLIB.cmake

.include "../../mk/bsd.prefs.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/swig3/buildlink3.mk"
.include "../../devel/tclap/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/freeglut/buildlink3.mk"
.endif
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libpano13/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/vigra/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
