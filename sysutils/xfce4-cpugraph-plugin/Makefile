# $NetBSD: Makefile,v 1.46 2018/11/14 22:22:28 kleink Exp $

PKGREVISION= 10
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-cpugraph-plugin-1.0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-cpugraph-plugin/1.0/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-cpugraph-plugin
COMMENT=	Xfce CPU load plugin

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
