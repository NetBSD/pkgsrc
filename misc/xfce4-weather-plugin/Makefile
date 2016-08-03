# $NetBSD: Makefile,v 1.45 2016/08/03 10:23:10 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.8.7
DISTNAME=	xfce4-weather-plugin-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-weather-plugin/0.8/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-weather-plugin
COMMENT=	Xfce weather plugin

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../net/libsoup/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
