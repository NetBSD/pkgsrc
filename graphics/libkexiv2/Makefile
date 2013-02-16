# $NetBSD: Makefile,v 1.39 2013/02/16 11:22:16 wiz Exp $
#

DISTNAME=	libkexiv2-${_KDE_VERSION}
PKGREVISION=	7
CATEGORIES=	graphics
COMMENT=	a KDE wrapper around exiv2

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkexiv2.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
