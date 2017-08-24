# $NetBSD: Makefile,v 1.36 2017/08/24 20:02:59 adam Exp $

DISTNAME=	libksane-15.08.3
PKGREVISION=	5
CATEGORIES=	graphics
COMMENT=	SANE Library interface for KDE
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=    libksane.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
