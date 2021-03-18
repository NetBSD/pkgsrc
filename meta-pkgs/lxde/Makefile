# $NetBSD: Makefile,v 1.2 2021/03/18 02:19:02 gutteridge Exp $

META_PACKAGE=	yes

DISTNAME=	lxde-1.0
PKGREVISION=	1
CATEGORIES=	meta-pkgs
COMMENT=	Lxde

MAINTAINER=	youri@NetBSD.org
LICENSE=	gnu-gpl-v2

DEPENDS+=	lxmenu-data>=0.1.5nb1:../../sysutils/lxmenu-data
DEPENDS+=	lxappearance>=0.6.3nb6:../../x11/lxappearance
DEPENDS+=	obconf>=2.0.4nb15:../../wm/obconf
DEPENDS+=	gpicview>=0.2.5nb11:../../graphics/gpicview
DEPENDS+=	openbox>=3.6.1nb15:../../wm/openbox
DEPENDS+=	lxpanel>=0.10.1nb1:../../sysutils/lxpanel
DEPENDS+=	lxde-common>=0.99.2:../../x11/lxde-common
DEPENDS+=	menu-cache>=1.1.0nb1:../../sysutils/menu-cache
DEPENDS+=	lxrandr>=0.3.2nb3:../../x11/lxrandr
DEPENDS+=	lxterminal>=0.4.0:../../x11/lxterminal
DEPENDS+=	lxlauncher>=0.2.5nb11:../../x11/lxlauncher
DEPENDS+=	lxsession>=0.5.5:../../x11/lxsession
DEPENDS+=	lxde-icon-theme>=0.5.1:../../graphics/lxde-icon-theme
DEPENDS+=	pcmanfm>=1.3.2nb1:../../sysutils/pcmanfm
DEPENDS+=	lxinput>=0.3.5nb11:../../x11/lxinput
DEPENDS+=	lxtask>=0.1.9nb3:../../sysutils/lxtask
DEPENDS+=	lxhotkey>=0.1.1:../../x11/lxhotkey

pre-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
