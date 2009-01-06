# $NetBSD: Makefile,v 1.5 2009/01/06 18:41:26 drochner Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.5.2

DISTNAME=	xarchiver-${XFCE4_VERSION}
PKGNAME=	xfce4-xarchiver-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xarchiver/}
COMMENT=	Xfce archiver handler

USE_DIRS+=	xdg-1.1

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
