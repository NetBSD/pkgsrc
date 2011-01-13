# $NetBSD: Makefile,v 1.19 2011/01/13 13:36:50 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.5.1

DISTNAME=	xfce4-xmms-plugin-${XFCE4_VERSION}
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-xmms-plugin/
COMMENT=	Xfce XMMS plugin

.include "options.mk"

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
