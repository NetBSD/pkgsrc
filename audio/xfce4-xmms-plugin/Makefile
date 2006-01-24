# $NetBSD: Makefile,v 1.9 2006/01/24 07:31:56 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.1

DISTNAME=	xfce4-xmms-plugin-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	Xfce XMMS plugin

EXTRACT_SUFX=	.tar.bz2

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
