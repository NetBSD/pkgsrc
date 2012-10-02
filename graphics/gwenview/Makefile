# $NetBSD: Makefile,v 1.57 2012/10/02 17:11:13 tron Exp $

DISTNAME=	gwenview-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	graphics
COMMENT=	KDE image viewer

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
