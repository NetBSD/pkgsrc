# $NetBSD: Makefile,v 1.194 2023/03/12 14:36:29 wiz Exp $

DISTNAME=	digiKam-7.9.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=digikam/${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.digikam.org/
COMMENT=	Advanced digital photo management application
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${DISTNAME:tl}

.include "../../meta-pkgs/kde/applications.mk"

REPLACE_PERL=	core/data/scripts/digitaglinktree/digitaglinktree
CMAKE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_KF5AkonadiContact:BOOL=TRUE

USE_TOOLS+=	flex bison msgmerge perl:run pkg-config

CXXFLAGS.NetBSD+=	-D_KERNTYPES

CHECK_PORTABILITY_SKIP+=	*.desktop.cmake.in

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/knotifications/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/threadweaver/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libksane/buildlink3.mk"
.include "../../graphics/liblqr/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../misc/libkvkontakte/buildlink3.mk"
.include "../../misc/marble/buildlink3.mk"
# qt5-qtwebengine pulls in ffmpeg4
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
# TODO: detection for this fails, find out why
.include "../../sysutils/kfilemetadata5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxslt/buildlink3.mk"
#.include "../../wip/akonadi-contacts/buildlink3.mk"
.include "../../time/kcalendarcore/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
# unpackaged: qtav
.include "../../mk/bsd.pkg.mk"
