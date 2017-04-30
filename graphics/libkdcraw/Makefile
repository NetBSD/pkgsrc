# $NetBSD: Makefile,v 1.59 2017/04/30 01:21:22 ryoon Exp $

DISTNAME=	libkdcraw-15.08.3
PKGREVISION=	4
CATEGORIES=	graphics
COMMENT=	KDE digital camera raw image library wrapper
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libkdcraw.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libraw/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
