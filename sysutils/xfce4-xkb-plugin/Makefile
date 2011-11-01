# $NetBSD: Makefile,v 1.20 2011/11/01 06:02:37 sbd Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.3

DISTNAME=	xfce4-xkb-plugin-${XFCE4_VERSION}
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-xkb-plugin/
COMMENT=	Xfce Keyboard plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
