# $NetBSD: Makefile,v 1.52 2018/11/14 22:22:29 kleink Exp $

PKGREVISION= 6
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.2.1
DISTNAME=	xfce4-systemload-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-systemload-plugin/${VERSION:R}/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-systemload-plugin
COMMENT=	Xfce system load plugin

MAKE_ENV.DragonFly+=	OS_LIBS=-lkinfo

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
