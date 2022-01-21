# $NetBSD: Makefile,v 1.10 2022/01/21 07:28:03 pin Exp $

PKGNAME=	lxqt-1.0.0
PKGREVISION=    2
CATEGORIES=	meta-pkgs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Meta-package for the LXQt desktop environment

META_PACKAGE=	yes

.include "options.mk"

TOOL_DEPENDS+=	lxqt-build-tools>=0.10.0:../../devel/lxqt-build-tools

DEPENDS+=	libqtxdg>=3.8.0:../../x11/libqtxdg
DEPENDS+=	liblxqt>=1.0.0:../../x11/liblxqt
DEPENDS+=	libfm-qt>=1.0.0:../../x11/libfm-qt
DEPENDS+=	lxqt-themes>=1.0.0:../../graphics/lxqt-themes
DEPENDS+=	pavucontrol-qt>=1.0.0:../../audio/pavucontrol-qt
DEPENDS+=	qtermwidget>=1.0.0:../../x11/qtermwidget
DEPENDS+=	lximage-qt>=1.0.0:../../graphics/lximage-qt
DEPENDS+=	lxqt-about>=1.0.0:../../x11/lxqt-about
DEPENDS+=	lxqt-policykit>=1.0.0:../../security/lxqt-policykit
DEPENDS+=	lxqt-admin>=1.0.0:../../x11/lxqt-admin
DEPENDS+=	lxqt-config>=1.0.0:../../x11/lxqt-config
DEPENDS+=	lxqt-globalkeys>=1.0.1:../../x11/lxqt-globalkeys
DEPENDS+=	lxqt-openssh-askpass>=1.0.0:../../security/lxqt-openssh-askpass
DEPENDS+=	lxqt-notificationd>=1.0.0:../../x11/lxqt-notificationd
DEPENDS+=	lxqt-powermanagement>=1.0.0:../../sysutils/lxqt-powermanagement
DEPENDS+=	lxqt-qtplugin>=1.0.0:../../x11/lxqt-qtplugin
DEPENDS+=	lxqt-session>=1.0.1:../../x11/lxqt-session
DEPENDS+=	lxqt-sudo>=1.0.0:../../security/lxqt-sudo
DEPENDS+=	pcmanfm-qt>=1.0.0:../../sysutils/pcmanfm-qt
DEPENDS+=	qterminal>=1.0.0:../../x11/qterminal
DEPENDS+=	lxqt-panel>=1.0.0:../../x11/lxqt-panel
DEPENDS+=	lxqt-runner>=1.0.0:../../x11/lxqt-runner
DEPENDS+=	screengrab>=2.3.0:../../graphics/screengrab
DEPENDS+=	lxqt-archiver>=0.5.0:../../archivers/lxqt-archiver
# The Oxygen icon set is the default that LXQt expects, and a compatible icon
# theme must be present for it to be fully usable. Breeze is another option.
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver
# This pulls in quite a lot of dependencies, but, if translations are wanted,
# it's needed.
DEPENDS+=	qt5-qttranslations>=5.15.2:../../x11/qt5-qttranslations
# This is needed to be able to correctly use deadkeys
DEPENDS+=	uim-[0-9]*:../../inputmethod/uim

.include "../../mk/bsd.pkg.mk"
