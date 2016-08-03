# $NetBSD: Makefile,v 1.33 2016/08/03 10:23:13 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-mpc-plugin-0.4.99
CATEGORIES=	multimedia
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-mpc-plugin/0.4/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-mpc-plugin
COMMENT=	Xfce Music Player Client plugin

LIBS.SunOS+=	-lsocket -lnsl

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
