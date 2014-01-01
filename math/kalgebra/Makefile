# $NetBSD: Makefile,v 1.19 2014/01/01 11:52:23 wiz Exp $

DISTNAME=	kalgebra-${_KDE_VERSION}
PKGREVISION=	1
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
