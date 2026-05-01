# $NetBSD: Makefile,v 1.46 2026/05/01 06:11:57 wiz Exp $

PKGNAME=	lxqt-2.4.0
CATEGORIES=	meta-pkgs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt-project.org/
COMMENT=	Meta-package for the LXQt desktop environment

META_PACKAGE=	yes

.include "options.mk"

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools

DEPENDS+=	libqtxdg>=4.4.0:../../x11/libqtxdg
DEPENDS+=	qtxdg-tools>=4.4.0:../../x11/qtxdg-tools
DEPENDS+=	liblxqt>=2.4.0:../../x11/liblxqt
DEPENDS+=	lxqt-menu-data>=2.4.0:../../sysutils/lxqt-menu-data
DEPENDS+=	libfm-qt>=2.4.0:../../x11/libfm-qt
DEPENDS+=	lxqt-themes>=2.4.0:../../graphics/lxqt-themes
DEPENDS+=	pavucontrol-qt>=2.4.0:../../audio/pavucontrol-qt
DEPENDS+=	qtermwidget>=2.4.0:../../x11/qtermwidget
DEPENDS+=	lximage-qt>=2.4.0:../../graphics/lximage-qt
DEPENDS+=	lxqt-about>=2.4.0:../../x11/lxqt-about
DEPENDS+=	lxqt-policykit>=2.4.0:../../security/lxqt-policykit
DEPENDS+=	lxqt-admin>=2.4.0:../../x11/lxqt-admin
DEPENDS+=	lxqt-config>=2.4.0:../../x11/lxqt-config
DEPENDS+=	lxqt-globalkeys>=2.4.0:../../x11/lxqt-globalkeys
DEPENDS+=	lxqt-openssh-askpass>=2.4.0:../../security/lxqt-openssh-askpass
DEPENDS+=	lxqt-notificationd>=2.4.0:../../x11/lxqt-notificationd
DEPENDS+=	lxqt-powermanagement>=2.4.0:../../sysutils/lxqt-powermanagement
DEPENDS+=	libdbusmenu-lxqt>=0.4.0:../../devel/libdbusmenu-lxqt
DEPENDS+=	lxqt-qtplugin>=2.4.0:../../x11/lxqt-qtplugin
DEPENDS+=	lxqt-session>=2.4.0:../../x11/lxqt-session
DEPENDS+=	lxqt-sudo>=2.4.0:../../security/lxqt-sudo
DEPENDS+=	pcmanfm-qt>=2.4.0:../../sysutils/pcmanfm-qt
DEPENDS+=	qterminal>=2.4.0:../../x11/qterminal
DEPENDS+=	lxqt-panel>=2.4.0:../../x11/lxqt-panel
DEPENDS+=	lxqt-runner>=2.4.0:../../x11/lxqt-runner
DEPENDS+=	screengrab>=3.2.0:../../graphics/screengrab
DEPENDS+=	lxqt-archiver>=1.4.0:../../archivers/lxqt-archiver
# The Breeze icon set is the default that LXQt expects, and a compatible icon
# theme must be present for the DE to be fully usable.
DEPENDS+=	breeze-icons-[0-9]*:../../graphics/breeze-icons
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver
# This pulls in quite a lot of dependencies, but, if translations are wanted,
# it's needed.
DEPENDS+=	qt6-qttranslations-[0-9]*:../../x11/qt6-qttranslations

.include "../../mk/bsd.pkg.mk"
