# $NetBSD: Makefile,v 1.39 2025/05/19 09:10:46 pin Exp $

DISTNAME=	screengrab-3.0.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/screengrab/
COMMENT=	Crossplatform tool for grabbing screenshots of your desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/screengrab \
		-L${PREFIX}/lib/screengrab/

TOOL_DEPENDS+=	lxqt-build-tools>=2.2.0:../../devel/lxqt-build-tools
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
