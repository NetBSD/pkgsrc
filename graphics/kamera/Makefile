# $NetBSD: Makefile,v 1.36 2018/04/03 06:14:55 wiz Exp $

DISTNAME=	kamera-${_KDE_VERSION}
PKGREVISION=	10
CATEGORIES=	graphics
COMMENT=	KDE digital camera manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
