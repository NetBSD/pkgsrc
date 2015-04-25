# $NetBSD: Makefile,v 1.59 2015/04/25 14:23:16 tnn Exp $
#

DISTNAME=	libkexiv2-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	graphics
COMMENT=	KDE wrapper around exiv2

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkexiv2.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
