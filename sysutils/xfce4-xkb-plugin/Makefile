# $NetBSD: Makefile,v 1.24 2012/07/15 08:22:56 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.3

DISTNAME=	xfce4-xkb-plugin-${XFCE4_VERSION}
PKGREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-xkb-plugin/
COMMENT=	Xfce Keyboard plugin

LDFLAGS.DragonFly=	-lX11

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
