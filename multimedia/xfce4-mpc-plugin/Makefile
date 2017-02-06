# $NetBSD: Makefile,v 1.34 2017/02/06 13:55:47 wiz Exp $

PKGREVISION= 2
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
