# $NetBSD: Makefile,v 1.78 2019/07/01 04:07:48 ryoon Exp $

DISTNAME=	libkipi-15.08.3
PKGREVISION=	8
CATEGORIES=	graphics
COMMENT=	KDE image plugin interface
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkipi.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
