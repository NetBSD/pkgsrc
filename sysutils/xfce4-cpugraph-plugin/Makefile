# $NetBSD: Makefile,v 1.57 2021/12/08 16:06:40 adam Exp $

PKGREVISION= 7
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-cpugraph-plugin-1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-cpugraph-plugin/1.1/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-cpugraph-plugin
COMMENT=	Xfce CPU load plugin

USE_LANGUAGES=	c99

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
