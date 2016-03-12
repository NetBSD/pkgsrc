# $NetBSD: Makefile,v 1.41 2016/03/12 11:28:36 ryoon Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-xkb-plugin-0.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-xkb-plugin/0.7/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-xkb-plugin
COMMENT=	Xfce Keyboard plugin

LDFLAGS.DragonFly=	-lX11
LDFLAGS.SunOS+=		-lX11

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
