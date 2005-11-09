# $NetBSD: Makefile,v 1.4 2005/11/09 07:09:04 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.2

DISTNAME=	xfce4-cpugraph-plugin-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	Xfce CPU load plugin

WRKSRC=		${WRKDIR}/xfce4-cpugraph-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
