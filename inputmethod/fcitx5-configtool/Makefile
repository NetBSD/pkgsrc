# $NetBSD: Makefile,v 1.21 2024/05/29 16:33:08 adam Exp $

DISTNAME=	fcitx5-configtool-5.1.3
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-configtool/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-configtool
COMMENT=	Config tool for fcitx5
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

TOOL_DEPENDS+=		extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

CMAKE_ARGS+=		-DENABLE_KCM=off

# CMAKE_INSTALL_RPATH does not work.
SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Setting RPATH
SUBST_FILES.rpath+=	src/migrator/lib/CMakeLists.txt
SUBST_VARS.rpath+=	COMPILER_RPATH_FLAG PREFIX QTDIR

#.include "../../devel/kcoreaddons/buildlink3.mk"
#.include "../../devel/kdeclarative/buildlink3.mk"
#.include "../../devel/ki18n/buildlink3.mk"
#.include "../../devel/kpackage/buildlink3.mk"
.include "../../inputmethod/fcitx5-qt/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
#.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
#.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
