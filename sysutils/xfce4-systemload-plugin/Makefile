# $NetBSD: Makefile,v 1.19 2010/09/14 11:01:13 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.2

DISTNAME=	xfce4-systemload-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-systemload-plugin/
COMMENT=	Xfce system load plugin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
MAKE_ENV+=	OS_LIBS=-lkinfo
.endif

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
