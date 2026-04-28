# $NetBSD: Makefile,v 1.45 2026/04/28 08:37:54 pin Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	screengrab-3.2.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/screengrab/
COMMENT=	Crossplatform tool for grabbing screenshots of your desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/screengrab \
		-L${PREFIX}/lib/screengrab/

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
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
