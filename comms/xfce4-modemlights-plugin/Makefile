# $NetBSD: Makefile,v 1.11 2018/11/14 22:21:11 kleink Exp $

PKGREVISION= 9
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-modemlights-plugin-0.1.3.99
CATEGORIES=	comms
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-modemlights-plugin/0.1/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-modemlights-plugin
COMMENT=	Xfce modems monitoring plugin

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
