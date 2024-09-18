# $NetBSD: Makefile,v 1.133 2024/09/18 14:01:30 gdt Exp $

DISTNAME=	merkaartor-0.20.0
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=openstreetmap/}
GITHUB_PROJECT=	merkaartor
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.merkaartor.be/
COMMENT=	OpenStreetMap mapping program
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
# Not documented, but in CMakeLists.txt.
USE_CC_FEATURES+=	c+17

USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"

CMAKE_CONFIGURE_ARGS+=	-DGPSD=ON

# Dependencies, generally in the order they are searched for, or
# ordered following pkgsrc conventions.

.include "../../x11/qt5-qtbase/buildlink3.mk"
# qt5 fragments not searched for but used during the build.
.include "../../x11/qt5-qtnetworkauth/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
# qt5 fragments not searched for and apparently not used, but were
# listed in earlier versions of the package.  Left as hints for future
# debugging.
#.include "../../x11/qt5-qttools/buildlink3.mk"
#.include "../../x11/qt5-qtconnectivity/buildlink3.mk"
#.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
#.include "../../x11/qt5-qtimageformats/buildlink3.mk"
#.include "../../x11/qt5-qtquickcontrols/buildlink3.mk"
#.include "../../x11/qt5-qtserialport/buildlink3.mk"
#.include "../../x11/qt5-qtwebkit/buildlink3.mk"
#.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"

# Due to GPSD=ON.
.include "../../geography/gpsd/buildlink3.mk"

# Standard pkgsrc.
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
