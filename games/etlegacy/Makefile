# $NetBSD: Makefile,v 1.6 2019/06/27 16:05:11 nia Exp $

PKGNAME=	etlegacy-2.76
PKGREVISION=	4
CATEGORIES=	games

DIST_SUBDIR=	etlegacy-${PKGVERSION_NOREV}

DISTFILES+=	etlegacy.tar.gz
DISTFILES+=	etlegacy-libs.tar.gz

LIBS_TAG=	f04f846898a92d36fd9cfe7425b1ab4d31bca794

SITES.etlegacy.tar.gz= \
    -https://github.com/etlegacy/etlegacy/archive/v${PKGVERSION_NOREV}.tar.gz

SITES.etlegacy-libs.tar.gz= \
    -https://github.com/etlegacy/etlegacy-libs/archive/${LIBS_TAG}.tar.gz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.etlegacy.com/
COMMENT=	Open source Wolfenstein: Enemy Territory client and server
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DRENDERER_DYNAMIC=OFF
CMAKE_ARGS+=	-DFEATURE_RENDERER2=OFF # experimental, buggy

# use libraries from pkgsrc
CMAKE_ARGS+=	-DBUNDLED_CURL=OFF
CMAKE_ARGS+=	-DBUNDLED_FREETYPE=OFF
CMAKE_ARGS+=	-DBUNDLED_GLEW=OFF
CMAKE_ARGS+=	-DBUNDLED_JANSSON=OFF
CMAKE_ARGS+=	-DBUNDLED_JPEG=OFF
CMAKE_ARGS+=	-DBUNDLED_LUA=OFF
CMAKE_ARGS+=	-DBUNDLED_OGG_VORBIS=OFF
CMAKE_ARGS+=	-DBUNDLED_OPENAL=OFF
CMAKE_ARGS+=	-DBUNDLED_OPENSSL=OFF
CMAKE_ARGS+=	-DBUNDLED_SDL=OFF
CMAKE_ARGS+=	-DBUNDLED_SQLITE3=OFF
CMAKE_ARGS+=	-DBUNDLED_THEORA=OFF
CMAKE_ARGS+=	-DBUNDLED_ZLIB=OFF

# don't try to build i386 binaries on amd64
CMAKE_ARGS+=	-DCROSS_COMPILE32=OFF

CMAKE_ARGS+=	-DFEATURE_AUTOUPDATE=OFF

# tries to install binaries
# but maybe this can be built from source separately
CMAKE_ARGS+=	-DFEATURE_OMNIBOT=OFF
CMAKE_ARGS+=	-DINSTALL_OMNIBOT=OFF

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DINSTALL_DEFAULT_BASEDIR="${PREFIX}/share/etlegacy"
CMAKE_ARGS+=	-DINSTALL_DEFAULT_BINDIR="bin"
CMAKE_ARGS+=	-DINSTALL_DEFAULT_MODDIR="share/etlegacy"

# don't use fopen64 etc
CFLAGS+=	-DIOAPI_NO_64

CHECK_PORTABILITY_SKIP+=	libs/sdl2/build-scripts/*

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=	ARCH_STRING="x86_64"
.elif ${MACHINE_ARCH} == "i386"
PLIST_SUBST+=	ARCH_STRING="i386"
.elif ${MACHINE_ARCH} == "alpha"
PLIST_SUBST+=	ARCH_STRING="alpha"
.elif ${MACHINE_ARCH} == "hppa"
PLIST_SUBST+=	ARCH_STRING="hppa"
.elif !empty(MACHINE_ARCH:Mpowerpc64*)
PLIST_SUBST+=	ARCH_STRING="ppc64"
.elif !empty(MACHINE_ARCH:Mpowerpc*)
PLIST_SUBST+=	ARCH_STRING="ppc"
.elif !empty(MACHINE_ARCH:Msh3*)
PLIST_SUBST+=	ARCH_STRING="sh"
.elif !empty(MACHINE_ARCH:Mmips*)
PLIST_SUBST+=	ARCH_STRING="mips"
.elif !empty(MACHINE_ARCH:Msparc*)
PLIST_SUBST+=	ARCH_STRING="sparc"
.elif !empty(MACHINE_ARCH:M*arm*)
PLIST_SUBST+=	ARCH_STRING="arm"
.else
# maybe architecture-neutral shared objects could be generated
PKG_SKIP_REASON+=\
	"unsupported MACHINE_ARCH, maybe needs to be added to q_platform.h"
.endif

post-extract:
	${MV} ${WRKDIR}/etlegacy-libs-${LIBS_TAG}/* \
	    ${WRKDIR}/etlegacy-${PKGVERSION_NOREV}/libs

.include "options.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
