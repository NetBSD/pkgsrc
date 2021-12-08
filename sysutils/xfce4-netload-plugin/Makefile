# $NetBSD: Makefile,v 1.63 2021/12/08 16:06:41 adam Exp $

PKGREVISION= 5
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-netload-plugin-1.3.2
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-netload-plugin/1.3/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-netload-plugin
COMMENT=	Xfce network load plugin

LDFLAGS.SunOS+=	-lnsl

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
