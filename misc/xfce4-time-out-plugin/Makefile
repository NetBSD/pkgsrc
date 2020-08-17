# $NetBSD: Makefile,v 1.21 2020/08/17 20:19:36 leot Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.1.1
DISTNAME=	xfce4-time-out-plugin-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-time-out-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-time-out-plugin
COMMENT=	Xfce periodical breaks plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
