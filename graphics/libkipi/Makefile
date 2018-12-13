# $NetBSD: Makefile,v 1.77 2018/12/13 19:51:34 adam Exp $

DISTNAME=	libkipi-15.08.3
PKGREVISION=	7
CATEGORIES=	graphics
COMMENT=	KDE image plugin interface
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkipi.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
