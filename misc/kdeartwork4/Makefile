# $NetBSD: Makefile,v 1.95 2024/03/04 22:06:32 wiz Exp $

DISTNAME=	kdeartwork-15.08.3
PKGNAME=	${DISTNAME:S/-1/4-1/}
PKGREVISION=	44
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

CMAKE_ARGS+=	-DXSCREENSAVER_CONFIG_DIR:PATH=${BUILDLINK_PREFIX.xscreensaver}/libexec/xscreensaver/config
CMAKE_ARGS+=	-DXSCREENSAVER_DIR:PATH=${BUILDLINK_PREFIX.xscreensaver}/libexec/xscreensaver
CMAKE_ARGS+=	-DWITH_Eigen3:BOOL=OFF
CMAKE_ARGS+=	-DWITH_Kexiv2:BOOL=OFF

#BUILD_MAKE_FLAGS+=	VERBOSE=1

# xscreensaver 6.x changed the name of a pre-existing screensaver, and
# also webcollage is now built by default when it was disabled before,
# which influences packaging here.
BUILDLINK_API_DEPENDS.xscreensaver+=	xscreensaver>=6.03

.include "../../meta-pkgs/kde4/kde4.mk"

#.include "../../graphics/libkexiv2-kde4/buildlink3.mk"
#.include "../../math/eigen3/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
