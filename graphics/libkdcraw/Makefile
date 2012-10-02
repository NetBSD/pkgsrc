# $NetBSD: Makefile,v 1.32 2012/10/02 17:11:15 tron Exp $

DISTNAME=	libkdcraw-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	graphics
COMMENT=	KDE digital camera raw image library wrapper

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkdcraw.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/lcms/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
