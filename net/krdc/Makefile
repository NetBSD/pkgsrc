# $NetBSD: Makefile,v 1.6 2014/05/15 14:41:57 adam Exp $

DISTNAME=	krdc-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	net
COMMENT=	KDE remote desktop client

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../net/libvncserver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
