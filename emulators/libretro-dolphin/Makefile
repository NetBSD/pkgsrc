# $NetBSD: Makefile,v 1.17 2020/05/31 18:36:29 nia Exp $

DISTNAME=	libretro-dolphin-20180827
PKGREVISION=	10
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	dolphin
GITHUB_TAG=	a5bce7d67abeaa9142d466a578ca5049197073e9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/dolphin/
COMMENT=	Libretro core based on the Dolphin GameCube/Wii emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++14
GCC_REQD+=	6

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DTRY_X11=OFF
CMAKE_ARGS+=	-DUSE_DISCORD_PRESENCE=OFF
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Git=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_HIDAPI=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_MbedTLS=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_OpenSLES=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_SFML=ON
CMAKE_ARGS+=	-DENABLE_BLUEZ=OFF
CMAKE_ARGS+=	-DENABLE_QT=OFF
CMAKE_ARGS+=	-DENABLE_SDL=OFF
CMAKE_ARGS+=	-DENABLE_EVDEV=OFF
CMAKE_ARGS+=	-DLIBRETRO=ON

.include "../../mk/bsd.prefs.mk"

# Big endian platforms not supported.
ONLY_FOR_PLATFORM=	${LITTLEENDIANPLATFORMS}

.if ${MACHINE_ARCH} != "x86_64" && ${MACHINE_ARCH} != "aarch64"
CMAKE_ARGS+=	-DENABLE_GENERIC=1
.endif

LDFLAGS.NetBSD+=	-lrt

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/dolphin_libretro.${SOEXT} \
	    ${DESTDIR}${PREFIX}/lib/libretro/dolphin_libretro.${SOEXT}

.if ${OPSYS} != "Darwin"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.if ${MESALIB_SUPPORTS_EGL} != "yes"
PKG_FAIL_REASON+=	"MesaLib has no EGL support."
.endif
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
