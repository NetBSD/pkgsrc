# $NetBSD: Makefile,v 1.10 2013/02/16 11:23:03 wiz Exp $

DISTNAME=	cantor-${_KDE_VERSION}
PKGREVISION=	7
CATEGORIES=	math
COMMENT=	KDE frontend to mathematical software

.include "../../meta-pkgs/kde4/Makefile.kde4"

CMAKE_ARGS+= -DWITH_Qalculate=OFF
CMAKE_ARGS+= -DWITH_R=OFF

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../math/analitza/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
