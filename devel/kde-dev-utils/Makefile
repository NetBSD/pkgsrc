# $NetBSD: Makefile,v 1.7 2014/05/15 14:41:46 adam Exp $

DISTNAME=	kde-dev-utils-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	devel
COMMENT=	Small utilities for developers using KDE/Qt libs/frameworks

.include "../../meta-pkgs/kde4/Makefile.kde4"

CMAKE_ARGS+=	-DBUILD_kmtrace:BOOL=OFF

# disable for the moment till sort out -ldl
CMAKE_ARGS+=	-DBUILD_kstartperf:BOOL=OFF

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
