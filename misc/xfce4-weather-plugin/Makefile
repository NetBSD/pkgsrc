# $NetBSD: Makefile,v 1.34 2013/06/06 12:54:00 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.6.2

DISTNAME=	xfce4-weather-plugin-${XFCE4_VERSION}
PKGREVISION=	20
CATEGORIES=	misc
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-weather-plugin/
COMMENT=	Xfce weather plugin

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
