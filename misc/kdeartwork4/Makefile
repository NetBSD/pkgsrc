# $NetBSD: Makefile,v 1.39 2013/11/07 12:35:41 markd Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

CMAKE_ARGS+=	-DXSCREENSAVER_CONFIG_DIR:PATH=${BUILDLINK_PREFIX.xscreensaver}/libexec/xscreensaver/config
CMAKE_ARGS+=	-DXSCREENSAVER_DIR:PATH=${BUILDLINK_PREFIX.xscreensaver}/libexec/xscreensaver

#BUILD_MAKE_FLAGS+= VERBOSE=1

BUILDLINK_API_DEPENDS.xscreensaver+=  xscreensaver>=5.10

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
