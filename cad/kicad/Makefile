# $NetBSD: Makefile,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
#

V=		20140214
DISTNAME=	kicad-stable-${V}
PKGNAME=	kicad-${V}
CATEGORIES=	cad
MASTER_SITES=	http://ftp.fr.NetBSD.org/~bouyer/kicad/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.kicad-pcb.org/
COMMENT=	Schematic and PCB CAD software (stable branch)
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CMAKE=		yes

CMAKE_ARGS+=		-DKICAD_STABLE_VERSION=ON
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release

CMAKE_MODULE_PATH_OVERRIDE = \
			bitmaps_png/CMakeLists.txt \
			new/CMakeLists.txt \
			tools/CMakeLists.txt

SUBST_CLASSES+=		macosx
SUBST_STAGE.macosx=	pre-configure
SUBST_MESSAGE.macosx=	Eliminating Mac OS X build specific for ${PKGNAME}
SUBST_FILES.macosx=	bitmap2component/CMakeLists.txt			\
			eeschema/CMakeLists.txt				\
			cvpcb/CMakeLists.txt				\
			gerbview/CMakeLists.txt				\
			kicad/CMakeLists.txt				\
			pcb_calculator/CMakeLists.txt			\
			pcbnew/CMakeLists.txt
SUBST_SED.macosx=	-e 's/[[:<:]]MACOSX_BUNDLE[[:>:]]//'

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
