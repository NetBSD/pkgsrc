# $NetBSD: Makefile,v 1.10 2018/11/12 03:51:49 ryoon Exp $

PKGREVISION= 8
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
