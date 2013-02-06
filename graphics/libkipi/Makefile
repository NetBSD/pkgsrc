# $NetBSD: Makefile,v 1.47 2013/02/06 23:21:32 jperkin Exp $

DISTNAME=	libkipi-${_KDE_VERSION}
PKGREVISION=	6
CATEGORIES=	graphics
COMMENT=	KDE image plugin interface

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkipi.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
