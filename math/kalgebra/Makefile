# $NetBSD: Makefile,v 1.6 2012/10/02 17:11:31 tron Exp $

DISTNAME=	kalgebra-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	math
COMMENT=	KDE graph calculator

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/analitza/buildlink3.mk"
.include "../../misc/libkdeedu/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
