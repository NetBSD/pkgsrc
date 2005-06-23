# $NetBSD: Makefile,v 1.7 2005/06/23 07:23:56 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.1

DISTNAME=	xfce4-xmms-plugin-${XFCE4_VERSION}
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 XMMS plugin

EXTRACT_SUFX=	.tar.bz2

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
