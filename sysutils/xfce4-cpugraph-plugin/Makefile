# $NetBSD: Makefile,v 1.1.1.1 2004/06/21 06:06:11 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.0

DISTNAME=	xfce4-cpugraph-plugin-${XFCE4_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 CPU load plugin

WRKSRC=		${WRKDIR}/xfce4-cpugraph-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
