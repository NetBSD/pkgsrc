# $NetBSD: Makefile,v 1.26 2012/10/02 17:11:49 tron Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.5.4

DISTNAME=	xfce4-wavelan-plugin-${XFCE4_VERSION}
PKGREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-wavelan-plugin/
EXTRACT_SUFX=	.tar.gz
COMMENT=	Xfce WLAN plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
