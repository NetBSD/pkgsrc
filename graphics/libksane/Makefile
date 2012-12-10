# $NetBSD: Makefile,v 1.8 2012/12/10 12:32:40 ryoon Exp $

DISTNAME=	libksane-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	graphics
COMMENT=	SANE Library interface for KDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libksane.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
