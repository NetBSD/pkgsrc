# $NetBSD: Makefile,v 1.25 2012/09/07 19:17:13 adam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.6.2

DISTNAME=	xfce4-weather-plugin-${XFCE4_VERSION}
PKGREVISION=	13
CATEGORIES=	misc
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-weather-plugin/
COMMENT=	Xfce weather plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
