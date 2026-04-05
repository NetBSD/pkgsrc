# $NetBSD: Makefile,v 1.270 2026/04/05 07:21:44 wiz Exp $

DISTNAME=	digiKam-9.0.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=digikam/${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.digikam.org/
COMMENT=	Advanced digital photo management application
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2.1

DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool

WRKSRC=		${WRKDIR}/${DISTNAME:tl}

.include "../../meta-pkgs/kde/applications.mk"

REPLACE_PERL=	core/data/scripts/digitaglinktree/digitaglinktree

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=TRUE
CMAKE_CONFIGURE_ARGS+=	-DENABLE_KFILEMETADATASUPPORT=ON

USE_TOOLS+=	flex bison msgmerge perl:run pkg-config

# not a shell script, '==' is correct
# see https://techbase.kde.org/Development/Tutorials/Solid/Device_Actions
CHECK_PORTABILITY_SKIP+=	core/data/hotplug/digikam-opencamera.desktop.cmake.in

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/liblqr/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/opencv-contrib-face/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
#.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxslt/buildlink3.mk"
# does not provide the library libakonadicontact that digikam is looking for
#.include "../../misc/akonadi-contacts/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/qt6-qtscxml/buildlink3.mk"
.include "../../security/qt6-qtnetworkauth/buildlink3.mk"
.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
# these ones are optional
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-threadweaver/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../graphics/libksane/buildlink3.mk"
.include "../../sysutils/kf6-kfilemetadata/buildlink3.mk"
.include "../../time/kf6-kcalendarcore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
