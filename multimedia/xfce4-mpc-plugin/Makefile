# $NetBSD: Makefile,v 1.54 2022/08/11 05:09:08 gutteridge Exp $

PKGREVISION= 7
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-mpc-plugin-0.5.2
CATEGORIES=	multimedia
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-mpc-plugin/0.5/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-mpc-plugin
COMMENT=	Xfce Music Player Client plugin

LIBS.SunOS+=	-lsocket -lnsl

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
