# $NetBSD: Makefile,v 1.6 2008/12/18 14:18:14 hira Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.14

DISTNAME=	mousepad-${XFCE4_VERSION}
PKGNAME=	xfce4-mousepad-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	editors
COMMENT=	Xfce text editor

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
