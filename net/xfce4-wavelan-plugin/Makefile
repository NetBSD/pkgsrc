# $NetBSD: Makefile,v 1.6 2005/02/10 12:22:29 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.1

DISTNAME=	xfce4-wavelan-plugin-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 WLAN plugin

# NetBSD 1.x does not have /usr/include/net80211/
NOT_FOR_PLATFORM=	NetBSD-1.[0-9]*-*

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
