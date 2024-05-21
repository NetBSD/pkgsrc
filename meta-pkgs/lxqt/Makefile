# $NetBSD: Makefile,v 1.26 2024/05/21 09:27:29 pin Exp $

PKGNAME=	lxqt-1.4.0
PKGREVISION=	5
CATEGORIES=	meta-pkgs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt-project.org/
COMMENT=	Meta-package for the LXQt desktop environment

META_PACKAGE=	yes

.include "options.mk"

TOOL_DEPENDS+=	lxqt-build-tools>=0.13.0:../../devel/lxqt-build-tools

DEPENDS+=	libqtxdg>=3.12.0:../../x11/libqtxdg
DEPENDS+=	qtxdg-tools>=3.12.0:../../x11/qtxdg-tools
DEPENDS+=	liblxqt>=1.4.0:../../x11/liblxqt
DEPENDS+=	lxqt-menu-data>=1.4.0:../../sysutils/lxqt-menu-data
DEPENDS+=	libfm-qt>=1.4.0:../../x11/libfm-qt
DEPENDS+=	lxqt-themes>=1.3.0:../../graphics/lxqt-themes
DEPENDS+=	pavucontrol-qt>=1.4.0:../../audio/pavucontrol-qt
DEPENDS+=	qtermwidget>=1.4.0:../../x11/qtermwidget
DEPENDS+=	lximage-qt>=1.4.0:../../graphics/lximage-qt
DEPENDS+=	lxqt-about>=1.4.0:../../x11/lxqt-about
DEPENDS+=	lxqt-policykit>=1.4.0:../../security/lxqt-policykit
DEPENDS+=	lxqt-admin>=1.4.0:../../x11/lxqt-admin
DEPENDS+=	lxqt-config>=1.4.0:../../x11/lxqt-config
DEPENDS+=	lxqt-globalkeys>=1.4.0:../../x11/lxqt-globalkeys
DEPENDS+=	lxqt-openssh-askpass>=1.4.0:../../security/lxqt-openssh-askpass
DEPENDS+=	lxqt-notificationd>=1.4.0:../../x11/lxqt-notificationd
DEPENDS+=	lxqt-powermanagement>=1.4.0:../../sysutils/lxqt-powermanagement
DEPENDS+=	lxqt-qtplugin>=1.4.1:../../x11/lxqt-qtplugin
DEPENDS+=	lxqt-session>=1.4.0:../../x11/lxqt-session
DEPENDS+=	lxqt-sudo>=1.4.0:../../security/lxqt-sudo
DEPENDS+=	pcmanfm-qt>=1.4.1:../../sysutils/pcmanfm-qt
DEPENDS+=	qterminal>=1.4.0:../../x11/qterminal
DEPENDS+=	lxqt-panel>=1.4.0:../../x11/lxqt-panel
DEPENDS+=	lxqt-runner>=1.4.0:../../x11/lxqt-runner
DEPENDS+=	screengrab>=2.7.0:../../graphics/screengrab
DEPENDS+=	lxqt-archiver>=0.9.1:../../archivers/lxqt-archiver
# The Breeze icon set is the default that LXQt expects, and a compatible icon
# theme must be present for the DE to be fully usable.
DEPENDS+=	breeze-icons-[0-9]*:../../graphics/breeze-icons
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver
# This pulls in quite a lot of dependencies, but, if translations are wanted,
# it's needed.
DEPENDS+=	qt5-qttranslations>=5.15.7:../../x11/qt5-qttranslations

.include "../../mk/bsd.pkg.mk"
