# $NetBSD: Makefile,v 1.22 2012/10/02 17:12:01 tron Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.0

DISTNAME=	xfce4-fsguard-plugin-${XFCE4_VERSION}
PKGREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-fsguard-plugin/
COMMENT=	Xfce disk space plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
