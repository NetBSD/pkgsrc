# $NetBSD: Makefile,v 1.23 2014/04/10 06:21:20 obache Exp $

DISTNAME=	libksane-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	graphics
COMMENT=	SANE Library interface for KDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libksane.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
