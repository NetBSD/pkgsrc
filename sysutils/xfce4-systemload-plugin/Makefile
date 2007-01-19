# $NetBSD: Makefile,v 1.14 2007/01/19 16:28:15 joerg Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.6

DISTNAME=	xfce4-systemload-plugin-${XFCE4_VERSION}
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	Xfce system load plugin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
MAKE_ENV+=	OS_LIBS=-lkinfo
.endif

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
