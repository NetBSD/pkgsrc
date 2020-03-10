# $NetBSD: Makefile,v 1.60 2020/03/10 22:11:03 wiz Exp $

PKGREVISION= 2
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
