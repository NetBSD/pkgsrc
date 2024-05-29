# $NetBSD: Makefile,v 1.31 2024/05/29 16:34:28 adam Exp $

DISTNAME=	lxqt-powermanagement-1.4.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-powermanagement/
COMMENT=	Daemon used for power management and auto-suspend
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

AUTOSTART_CONF=		share/examples/autostart
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/autostart

CONF_FILES+=	${AUTOSTART_CONF}/lxqt-powermanagement.desktop \
		${PKG_SYSCONFDIR}/autostart/lxqt-powermanagement.desktop

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.13.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
# The dbus option of qt5-qtbase must be enabled for this package to
# build, it's a hard dependency.
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../devel/kidletime/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../x11/lxqt-globalkeys/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
