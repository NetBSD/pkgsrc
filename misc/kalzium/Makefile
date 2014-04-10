# $NetBSD: Makefile,v 1.23 2014/04/10 06:21:30 obache Exp $

DISTNAME=	kalzium-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Periodic table of elements

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.eigen2+=  eigen2>=2.0.3
.include "../../math/eigen2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
