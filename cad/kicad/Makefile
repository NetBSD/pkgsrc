# $NetBSD: Makefile,v 1.33 2019/06/14 15:59:32 bouyer Exp $
#

V=		5.1.2
DISTNAME=	kicad-${V}
CATEGORIES=	cad
MASTER_SITES=	https://launchpad.net/kicad/5.0/${V}/+download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kicad-pcb.org/
COMMENT=	Schematic and PCB CAD software (stable branch)
LICENSE=	gnu-gpl-v3

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++11
USE_CMAKE=		yes

CMAKE_ARGS+=		-DKICAD_REPO_NAME=stable -DKICAD_BUILD_VERSION=${V}
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release -DKICAD_SKIP_BOOST=ON
CMAKE_ARGS+=		-DKICAD_SPICE=OFF -DKICAD_USE_OCE=OFF
CMAKE_ARGS+=		-DKICAD_SCRIPTING=OFF -DKICAD_SCRIPTING_MODULES=OFF
CMAKE_ARGS+=		-DKICAD_SCRIPTING_ACTION_MENU=OFF
CMAKE_ARGS+=		-DKICAD_SCRIPTING_WXPYTHON=OFF

CMAKE_MODULE_PATH_OVERRIDE = \
			new/CMakeLists.txt

PY_PATCHPLIST=		yes

SUBST_CLASSES+=		macosx
SUBST_STAGE.macosx=	pre-configure
SUBST_MESSAGE.macosx=	Eliminating Mac OS X build specific for ${PKGNAME}
SUBST_FILES.macosx=	bitmap2component/CMakeLists.txt \
			kicad/CMakeLists.txt
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

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
