# $NetBSD: Makefile,v 1.54 2015/04/25 14:23:16 tnn Exp $

DISTNAME=	libkdcraw-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	graphics
COMMENT=	KDE digital camera raw image library wrapper

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkdcraw.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libraw/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
