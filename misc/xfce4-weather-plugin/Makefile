# $NetBSD: Makefile,v 1.9 2007/04/12 09:55:11 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.6.0

DISTNAME=	xfce4-weather-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-weather-plugin/
COMMENT=	Xfce weather plugin

USE_TOOLS+=	intltool

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
