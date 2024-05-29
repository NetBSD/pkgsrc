# $NetBSD: Makefile,v 1.129 2024/05/29 16:32:58 adam Exp $

DISTNAME=		krita-5.2.2
PKGREVISION=		5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_KDE:=krita/${PKGVERSION_NOREV}/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.krita.org/
COMMENT=		Raster graphics editor for digital painting
LICENSE=		gnu-gpl-v3

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=		msgfmt pkg-config perl
# Uses targets with spaces in the names
USE_TOOLS+=		gmake
#CMAKE_ARGS+=		-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_PyQt5:BOOL=true

DEPENDS+=	kitemmodels-[0-9]*:../../devel/kitemmodels

CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kritarc \
		${PKG_SYSCONFDIR}/xdg/kritarc

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	libs/ui/tests/data/AppImageUpdateDummy

SUBST_CLASSES+=		fix-moc
SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/plugins/*/*/CMakeFiles/*_autogen.dir/AutogenInfo.json
SUBST_NOOP_OK.fix-moc=	yes
SUBST_SED.fix-moc=	-e 's;"${PREFIX}/include",;;g'

.include "../../lang/python/application.mk"
.include "../../archivers/karchive/buildlink3.mk"
.include "../../archivers/quazip/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-header+=	boost-headers>=1.73.0nb1
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/immer/buildlink3.mk"
.include "../../devel/lager/buildlink3.mk"
.include "../../devel/zug/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/kcrash/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libmypaint/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/opencolorio/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../multimedia/mlt/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../textproc/libunibreak/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kguiaddons/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
