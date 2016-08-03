# $NetBSD: Makefile,v 1.43 2016/08/03 10:23:26 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-systemload-plugin-1.1.99
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-systemload-plugin/1.1/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-systemload-plugin
COMMENT=	Xfce system load plugin

MAKE_ENV.DragonFly+=	OS_LIBS=-lkinfo

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
