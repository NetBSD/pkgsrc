# $NetBSD: Makefile,v 1.27 2012/09/07 19:17:35 adam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.2

DISTNAME=	xfce4-systemload-plugin-${XFCE4_VERSION}
PKGREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-systemload-plugin/
COMMENT=	Xfce system load plugin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
MAKE_ENV+=	OS_LIBS=-lkinfo
.endif

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
