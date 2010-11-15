# $NetBSD: Makefile,v 1.13 2010/11/15 22:58:39 abs Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.4.0

DISTNAME=	xfce4-fsguard-plugin-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-fsguard-plugin/
COMMENT=	Xfce disk space plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
