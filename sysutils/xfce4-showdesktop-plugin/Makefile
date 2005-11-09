# $NetBSD: Makefile,v 1.9 2005/11/09 07:09:04 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.0

DISTNAME=	xfce4-showdesktop-plugin-${XFCE4_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	Xfce showdesktop plugin

WRKSRC=		${WRKDIR}/xfce4-showdesktop-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
