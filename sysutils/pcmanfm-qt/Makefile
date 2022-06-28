# $NetBSD: Makefile,v 1.22 2022/06/28 11:36:04 wiz Exp $

DISTNAME=	pcmanfm-qt-1.1.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/pcmanfm-qt/
COMMENT=	LXQt pcmanfm Qt frontend
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

AUTOSTART_CONF=		share/examples/autostart
SETTINGS_CONF=		share/examples/pcmanfm-qt/lxqt
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart \
			${PKG_SYSCONFDIR}/pcmanfm-qt/lxqt

CONF_FILES+=		${AUTOSTART_CONF}/lxqt-desktop.desktop \
			${PKG_SYSCONFDIR}/autostart/lxqt-desktop.desktop
CONF_FILES+=		${SETTINGS_CONF}/settings.conf \
			${PKG_SYSCONFDIR}/pcmanfm-qt/lxqt/settings.conf

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.11.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
DEPENDS+=	lxmenu-data-[0-9]*:../../sysutils/lxmenu-data

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../x11/libfm-qt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
