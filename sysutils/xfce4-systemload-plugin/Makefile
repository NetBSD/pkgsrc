# $NetBSD: Makefile,v 1.63 2021/12/11 14:10:05 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.3.1
DISTNAME=	xfce4-systemload-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-systemload-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-systemload-plugin
COMMENT=	Xfce system load plugin

MAKE_ENV.DragonFly+=	OS_LIBS=-lkinfo

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
