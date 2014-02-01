# $NetBSD: Makefile,v 1.71 2014/02/01 02:20:47 markd Exp $

DISTNAME=	gwenview-${_KDE_VERSION}
CATEGORIES=	graphics
COMMENT=	KDE image viewer

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/nepomuk-core/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kactivities/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
