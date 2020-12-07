# $NetBSD: Makefile,v 1.4 2020/12/07 13:05:37 pin Exp $

PKGNAME=	lxqt-0.16.0
CATEGORIES=	meta-pkgs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Meta-package for the LXQt desktop environment

META_PACKAGE=	yes

.include "options.mk"

TOOL_DEPENDS+=	lxqt-build-tools>=0.8.0:../../devel/lxqt-build-tools

DEPENDS+=	libqtxdg>=3.6.0:../../x11/libqtxdg
DEPENDS+=	liblxqt>=0.16.0:../../x11/liblxqt
DEPENDS+=	libfm-qt>=0.16.0:../../x11/libfm-qt
DEPENDS+=	lxqt-themes>=0.16.0:../../graphics/lxqt-themes
DEPENDS+=	pavucontrol-qt>=0.16.0:../../audio/pavucontrol-qt
DEPENDS+=	qtermwidget>=0.16.1:../../x11/qtermwidget
DEPENDS+=	lximage-qt>=0.16.0:../../graphics/lximage-qt
DEPENDS+=	lxqt-about>=0.16.0:../../x11/lxqt-about
DEPENDS+=	lxqt-policykit>=0.16.0:../../security/lxqt-policykit
DEPENDS+=	lxqt-admin>=0.16.0:../../x11/lxqt-admin
DEPENDS+=	lxqt-config>=0.16.1:../../x11/lxqt-config
DEPENDS+=	lxqt-globalkeys>=0.16.0:../../x11/lxqt-globalkeys
DEPENDS+=	lxqt-openssh-askpass>=0.16.0:../../security/lxqt-openssh-askpass
DEPENDS+=	lxqt-notificationd>=0.16.0:../../x11/lxqt-notificationd
DEPENDS+=	lxqt-powermanagement>=0.16.0:../../sysutils/lxqt-powermanagement
DEPENDS+=	lxqt-qtplugin>=0.16.0:../../x11/lxqt-qtplugin
DEPENDS+=	lxqt-session>=0.16.0:../../x11/lxqt-session
DEPENDS+=	lxqt-sudo>=0.16.0:../../security/lxqt-sudo
DEPENDS+=	pcmanfm-qt>=0.16.0:../../sysutils/pcmanfm-qt
DEPENDS+=	qterminal>=0.16.1:../../x11/qterminal
DEPENDS+=	lxqt-panel>=0.16.1:../../x11/lxqt-panel
DEPENDS+=	lxqt-runner>=0.16.0:../../x11/lxqt-runner
DEPENDS+=	screengrab>=2.1.0:../../graphics/screengrab
DEPENDS+=	lxqt-archiver>=0.3.0:../../archivers/lxqt-archiver
# The Oxygen icon set is the default that LXQt expects, and a compatible icon
# theme must be present for it to be fully usable. Breeze is another option.
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver
# This pulls in quite a lot of dependencies, but, if translations are wanted,
# it's needed.
DEPENDS+=	qt5-qttranslations>=5.15.1:../../x11/qt5-qttranslations

.include "../../mk/bsd.pkg.mk"
