# $NetBSD: Makefile,v 1.27 2012/10/02 17:12:02 tron Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.3

DISTNAME=	xfce4-xkb-plugin-${XFCE4_VERSION}
PKGREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-xkb-plugin/
COMMENT=	Xfce Keyboard plugin

LDFLAGS.DragonFly=	-lX11

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
