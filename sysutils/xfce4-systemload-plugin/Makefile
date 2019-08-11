# $NetBSD: Makefile,v 1.56 2019/08/11 13:23:20 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.2.2
DISTNAME=	xfce4-systemload-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-systemload-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-systemload-plugin
COMMENT=	Xfce system load plugin

MAKE_ENV.DragonFly+=	OS_LIBS=-lkinfo

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
