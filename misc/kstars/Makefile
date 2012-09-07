# $NetBSD: Makefile,v 1.15 2012/09/07 19:17:10 adam Exp $

DISTNAME=	kstars-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	KDE desktop planetarium

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.eigen2+=  eigen2>=2.0.3
.include "../../math/eigen2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
