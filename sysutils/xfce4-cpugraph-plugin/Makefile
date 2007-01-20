# $NetBSD: Makefile,v 1.8 2007/01/20 12:18:31 joerg Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.2

DISTNAME=	xfce4-cpugraph-plugin-${XFCE4_VERSION}
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	Xfce CPU load plugin

WRKSRC=		${WRKDIR}/xfce4-cpugraph-plugin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
MAKE_ENV+=	OS_LIBS=-lkinfo
.endif

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
