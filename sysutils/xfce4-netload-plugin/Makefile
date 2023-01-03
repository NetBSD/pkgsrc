# $NetBSD: Makefile,v 1.66 2023/01/03 17:38:17 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-netload-plugin-1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-netload-plugin/1.4/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-netload-plugin
COMMENT=	Xfce network load plugin

LDFLAGS.SunOS+=	-lnsl

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
