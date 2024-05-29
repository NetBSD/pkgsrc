# $NetBSD: Makefile,v 1.28 2024/05/29 16:33:03 adam Exp $

DISTNAME=	screengrab-2.7.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/screengrab/
COMMENT=	Crossplatform tool for grabbing screenshots of your desktop
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/screengrab \
		-L${PREFIX}/lib/screengrab/

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libqtxdg/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
