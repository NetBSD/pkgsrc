# $NetBSD: Makefile,v 1.2 2003/12/13 00:45:25 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.1.1

DISTNAME=	xfce4-showdesktop-plugin-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 showdesktop plugin

WRKSRC=		${WRKDIR}/xfce4-showdesktop-plugin

.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
