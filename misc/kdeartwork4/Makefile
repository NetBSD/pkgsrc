# $NetBSD: Makefile,v 1.42 2014/02/12 23:18:13 tron Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	1
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
