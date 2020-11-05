# $NetBSD: Makefile,v 1.163 2020/11/05 09:08:19 ryoon Exp $

DISTNAME=	digikam-6.4.0
PKGREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_KDE:=digikam/6.4.0/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.digikam.org/
COMMENT=	Advanced digital photo management application
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2.1
DIST_SUBDIR=	digikam-6.4.0-03

.include "../../meta-pkgs/kde/applications.mk"

REPLACE_PERL=	core/data/scripts/digitaglinktree/digitaglinktree
CMAKE_ARGS+=	-DBUILD_TESTING=OFF
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
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/lensfun/buildlink3.mk"
.include "../../graphics/libksane/buildlink3.mk"
.include "../../graphics/liblqr/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../misc/libkvkontakte/buildlink3.mk"
.include "../../misc/marble/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../sysutils/kfilemetadata5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../time/kcalendarcore/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
