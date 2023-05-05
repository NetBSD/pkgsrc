# $NetBSD: Makefile,v 1.64 2023/05/05 01:43:55 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.1.5
DISTNAME=	xfce4-battery-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-battery-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-battery-plugin
COMMENT=	Xfce battery monitor plugin

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
