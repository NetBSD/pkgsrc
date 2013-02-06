# $NetBSD: Makefile,v 1.38 2013/02/06 23:22:33 jperkin Exp $
#

DISTNAME=	libkexiv2-${_KDE_VERSION}
PKGREVISION=	6
CATEGORIES=	graphics
COMMENT=	a KDE wrapper around exiv2

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkexiv2.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
