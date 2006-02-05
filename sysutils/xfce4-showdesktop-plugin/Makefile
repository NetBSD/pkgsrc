# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:58 joerg Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.0

DISTNAME=	xfce4-showdesktop-plugin-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	Xfce showdesktop plugin

WRKSRC=		${WRKDIR}/xfce4-showdesktop-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
