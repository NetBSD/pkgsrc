# $NetBSD: Makefile,v 1.5 2005/01/20 17:41:25 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.1

DISTNAME=	xfce4-wavelan-plugin-${XFCE4_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 WLAN plugin

# NetBSD 1.x does not have /usr/include/net80211/
NOT_FOR_PLATFORM=	NetBSD-1.[0-9]*-*

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
