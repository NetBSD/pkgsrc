# $NetBSD: Makefile,v 1.26 2015/04/17 15:53:12 adam Exp $

DISTNAME=	kmix-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	multimedia
COMMENT=	KDE's soundcard mixer program

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
