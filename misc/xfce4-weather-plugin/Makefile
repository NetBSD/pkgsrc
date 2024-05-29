# $NetBSD: Makefile,v 1.98 2024/05/29 16:33:40 adam Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.11.2
DISTNAME=	xfce4-weather-plugin-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-weather-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-weather-plugin
COMMENT=	Xfce weather plugin

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
