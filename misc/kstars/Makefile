# $NetBSD: Makefile,v 1.77 2023/12/29 18:24:53 adam Exp $

DISTNAME=	kstars-${_KDE_VERSION}
PKGREVISION=	40
CATEGORIES=	misc
COMMENT=	KDE desktop planetarium

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#BUILDLINK_API_DEPENDS.eigen2+=  eigen2>=2.0.3
.include "../../math/eigen3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
