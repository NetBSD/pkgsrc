# $NetBSD: Makefile,v 1.32 2024/08/02 17:36:53 pin Exp $

DISTNAME=	lxqt-powermanagement-2.0.0
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

AUTOSTART_CONF=		share/examples/autostart
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/autostart

CONF_FILES+=	${AUTOSTART_CONF}/lxqt-powermanagement.desktop \
		${PKG_SYSCONFDIR}/autostart/lxqt-powermanagement.desktop

TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
# The dbus option of qt6-qtbase must be enabled for this package to
# build, it's a hard dependency.
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../devel/kf6-kidletime/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/lxqt-globalkeys/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
