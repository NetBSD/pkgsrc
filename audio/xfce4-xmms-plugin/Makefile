# $NetBSD: Makefile,v 1.6 2004/10/03 00:13:10 tv Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.1.1

DISTNAME=	xfce4-xmms-plugin-${XFCE4_VERSION}
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 XMMS plugin

EXTRACT_SUFX=	.tar.bz2

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
