# $NetBSD: Makefile,v 1.17 2012/07/15 08:22:49 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.16

DISTNAME=	mousepad-${XFCE4_VERSION}
PKGNAME=	xfce4-mousepad-${XFCE4_VERSION}
PKGREVISION=	9
CATEGORIES=	editors
COMMENT=	Xfce text editor

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
