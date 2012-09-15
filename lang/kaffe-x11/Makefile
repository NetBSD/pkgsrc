# $NetBSD: Makefile,v 1.33 2012/09/15 10:05:19 obache Exp $
#

.include "../../lang/kaffe/Makefile.common"

PKGNAME=    	${DISTNAME:S/kaffe/kaffe-x11/}
PKGREVISION=	17

COMMENT+=   (AWT support through X11)

CONFIGURE_ARGS+=  --with-kaffe-x-awt
CONFIGURE_ARGS+=  --enable-gtk-peer
CONFIGURE_ARGS+=  --with-x
CONFIGURE_ARGS+=  --without-esd
CONFIGURE_ARGS+=  --disable-esdtest

USE_TOOLS+=	pkg-config

BUILD_DIRS=	config
BUILD_DIRS+=	libraries/javalib/external/classpath
BUILD_DIRS+=	libraries/javalib/external/classpath
BUILD_DIRS+=	include
BUILD_DIRS+=	libraries/javalib
BUILD_DIRS+=	libraries/clib/awt
INSTALL_DIRS=	libraries/clib/awt
INSTALL_DIRS+=	libraries/javalib/external/classpath/native/jni/gtk-peer
INSTALL_DIRS+=	libraries/javalib/external/classpath/native/jawt

pre-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} BUILD_ENVIRONMENT

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/kaffe/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
