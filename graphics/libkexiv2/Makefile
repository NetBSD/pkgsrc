# $NetBSD: Makefile,v 1.48 2013/11/07 11:53:59 markd Exp $
#

DISTNAME=	libkexiv2-${_KDE_VERSION}
CATEGORIES=	graphics
COMMENT=	KDE wrapper around exiv2

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkexiv2.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
