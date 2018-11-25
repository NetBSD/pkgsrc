# $NetBSD: Makefile,v 1.49 2018/11/25 20:55:41 martin Exp $

PKGREVISION= 7
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.1.0
DISTNAME=	xfce4-battery-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-battery-plugin/1.1/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-battery-plugin
COMMENT=	Xfce battery monitor plugin

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
