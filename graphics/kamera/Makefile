# $NetBSD: Makefile,v 1.6 2012/10/02 17:11:13 tron Exp $

DISTNAME=	kamera-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	graphics
COMMENT=	KDE digital camera manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
