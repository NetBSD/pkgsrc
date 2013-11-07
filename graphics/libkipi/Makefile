# $NetBSD: Makefile,v 1.56 2013/11/07 11:53:59 markd Exp $

DISTNAME=	libkipi-${_KDE_VERSION}
CATEGORIES=	graphics
COMMENT=	KDE image plugin interface

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkipi.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
