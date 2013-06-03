# $NetBSD: Makefile,v 1.52 2013/06/03 10:05:16 wiz Exp $

DISTNAME=	libkipi-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	graphics
COMMENT=	KDE image plugin interface

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkipi.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
