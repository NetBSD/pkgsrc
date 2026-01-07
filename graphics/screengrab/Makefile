# $NetBSD: Makefile,v 1.43 2026/01/07 08:47:28 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	screengrab-3.1.0
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/screengrab/
COMMENT=	Crossplatform tool for grabbing screenshots of your desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/screengrab \
		-L${PREFIX}/lib/screengrab/

TOOL_DEPENDS+=	lxqt-build-tools>=2.3.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libqtxdg/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/plasma6-layer-shell-qt/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
