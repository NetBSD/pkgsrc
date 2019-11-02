# $NetBSD: Makefile,v 1.97 2019/11/02 18:39:52 maya Exp $

DISTNAME=	gwenview-${_KDE_VERSION}
PKGREVISION=	17
CATEGORIES=	graphics
COMMENT=	KDE image viewer

# Workaround cryptic issue where cmake CMAKE_COMPILER_IS_GNUCXX is not
# defined in this project (in FindKDE4Internal.cmake)
BUILDLINK_TRANSFORM+=	opt:-fno-exceptions:-fexceptions
BUILDLINK_TRANSFORM+=	opt:-DQT_NO_EXCEPTIONS:-UQT_EXCEPTIONS

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../misc/nepomuk-core/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libbaloo4/buildlink3.mk"
.include "../../sysutils/kfilemetadata/buildlink3.mk"
.include "../../x11/libkactivities4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
