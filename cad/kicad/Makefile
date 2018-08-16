# $NetBSD: Makefile,v 1.27 2018/08/16 18:54:36 adam Exp $
#

V=		4.0.7
DISTNAME=	kicad-${V}
PKGREVISION=	5
CATEGORIES=	cad
MASTER_SITES=	https://launchpad.net/kicad/4.0/${V}/+download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.kicad-pcb.org/
COMMENT=	Schematic and PCB CAD software (stable branch)
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++11
USE_CMAKE=		yes

CMAKE_ARGS+=		-DKICAD_REPO_NAME=stable -DKICAD_BUILD_VERSION=${V}
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release -DKICAD_SKIP_BOOST=ON

CMAKE_MODULE_PATH_OVERRIDE = \
			bitmaps_png/CMakeLists.txt \
			new/CMakeLists.txt \
			tools/CMakeLists.txt

SUBST_CLASSES+=		macosx
SUBST_STAGE.macosx=	pre-configure
SUBST_MESSAGE.macosx=	Eliminating Mac OS X build specific for ${PKGNAME}
SUBST_FILES.macosx=	cvpcb/CMakeLists.txt \
			eeschema/CMakeLists.txt \
			gerbview/CMakeLists.txt \
			kicad/CMakeLists.txt \
			pagelayout_editor/CMakeLists.txt \
			pcbnew/CMakeLists.txt \
			pcb_calculator/CMakeLists.txt
SUBST_SED.macosx=	-e 's/[[:<:]]MACOSX_BUNDLE[[:>:]]//'

.include "../../mk/bsd.prefs.mk"

# PR 48980: no fabsl on netbsd-5
.if !empty(MACHINE_PLATFORM:MNetBSD-5.*)
SUBST_CLASSES+=		netbsd5
SUBST_STAGE.netbsd5=	pre-patch
SUBST_MESSAGE.netbsd5=	Substituting fabs() for fabsl() for NetBSD-5
SUBST_FILES.netbsd5=	pcbnew/legacy_plugin.cpp        \
			tools/test-nm-biu-to-ascii-mm-round-tripping.cpp
SUBST_SED.netbsd5=	-e 's/fabsl/fabs/g'
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-error=non-pod-varargs
.endif

.include "../../devel/swig/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
