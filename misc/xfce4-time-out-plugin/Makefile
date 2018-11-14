# $NetBSD: Makefile,v 1.12 2018/11/14 22:22:04 kleink Exp $

PKGREVISION= 10
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-time-out-plugin-1.0.2
CATEGORIES=	misc
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-time-out-plugin/1.0/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-time-out-plugin
COMMENT=	Xfce periodical breaks plugin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
