# $NetBSD: Makefile,v 1.19 2012/01/09 02:54:28 obache Exp $

DISTNAME=	kdeadmin-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	misc
COMMENT=	System administration tools for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

REPLACE_PERL+=	knetworkconf/backends/network-conf.cmake
REPLACE_PERL+=	knetworkconf/backends/*.pl.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
