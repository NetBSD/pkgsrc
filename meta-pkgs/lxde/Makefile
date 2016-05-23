# $NetBSD: Makefile,v 1.1 2016/05/23 22:48:30 youri Exp $

META_PACKAGE=	yes

DISTNAME=	lxde-1.0
CATEGORIES=	meta-pkgs
COMMENT=	Lxde

MAINTAINER=	youri@NetBSD.org
LICENSE=	gnu-gpl-v2

DEPENDS+=	lxmenu-data-[0-9]*:../../sysutils/lxmenu-data
DEPENDS+=	lxappearance-[0-9]*:../../x11/lxappearance
DEPENDS+=	obconf-[0-9]*:../../wm/obconf
DEPENDS+=	gpicview-[0-9]*:../../graphics/gpicview
DEPENDS+=	openbox-[0-9]*:../../wm/openbox
DEPENDS+=	lxpanel-[0-9]*:../../sysutils/lxpanel
DEPENDS+=	lxde-common-[0-9]*:../../x11/lxde-common
DEPENDS+=	menu-cache-[0-9]*:../../sysutils/menu-cache
DEPENDS+=	lxrandr-[0-9]*:../../x11/lxrandr
DEPENDS+=	lxterminal-[0-9]*:../../x11/lxterminal
DEPENDS+=	lxlauncher-[0-9]*:../../x11/lxlauncher
DEPENDS+=	lxsession-[0-9]*:../../x11/lxsession
DEPENDS+=	lxde-icon-theme-[0-9]*:../../graphics/lxde-icon-theme
DEPENDS+=	pcmanfm-[0-9]*:../../sysutils/pcmanfm
DEPENDS+=	lxinput-[0-9]*:../../x11/lxinput
DEPENDS+=	lxtask-[0-9]*:../../sysutils/lxtask

pre-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
