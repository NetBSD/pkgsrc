# $NetBSD: Makefile,v 1.17 2010/09/14 11:01:13 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.5.1

DISTNAME=	xfce4-xmms-plugin-${XFCE4_VERSION}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-xmms-plugin/
COMMENT=	Xfce XMMS plugin

.include "options.mk"

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
