# $NetBSD: Makefile,v 1.172 2026/09/06 11:21:08 markd Exp $

DISTNAME=	krita-6.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=krita/${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.krita.org/
COMMENT=	Raster graphics editor for digital painting
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=		msgfmt pkg-config perl
# Uses targets with spaces in the names
USE_TOOLS+=		gmake
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_PyQt6:BOOL=true
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON
CMAKE_CONFIGURE_ARGS+=	-DALLOW_UNSTABLE=QT6

DEPENDS+=	kf6-kitemmodels-[0-9]*:../../devel/kf6-kitemmodels

REPLACE_PYTHON+=	libs/ui/tests/data/AppImageUpdateDummy

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/plugins/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../lang/python/application.mk"
.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../archivers/quazip1/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-header+=	boost-headers>=1.73.0nb1
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/immer/buildlink3.mk"
.include "../../devel/lager/buildlink3.mk"
.include "../../devel/zug/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/xsimd/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libmypaint/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/opencolorio/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../multimedia/mlt/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../print/poppler-qt6/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../textproc/libunibreak/buildlink3.mk"
.include "../../x11/kf6-kitemviews/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
