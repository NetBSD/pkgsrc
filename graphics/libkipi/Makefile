# $NetBSD: Makefile,v 1.79 2019/08/22 12:23:20 ryoon Exp $

DISTNAME=	libkipi-15.08.3
PKGREVISION=	9
CATEGORIES=	graphics
COMMENT=	KDE image plugin interface
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkipi.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
