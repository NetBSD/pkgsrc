# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 06:38:40 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.1.1

DISTNAME=	xfce4-xmms-plugin-${XFCE4_VERSION}
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 XMMS plugin

EXTRACT_SUFX=	.tar.bz2

.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
