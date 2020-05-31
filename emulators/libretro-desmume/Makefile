# $NetBSD: Makefile,v 1.12 2020/05/31 20:35:55 nia Exp $

DISTNAME=	libretro-desmume-20190426
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	desmume
GITHUB_TAG=	3069551c2e1de633c333739cca8bb7108ca3d3e9

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/desmume/
COMMENT=	Libretro core based on the DeSmuME Nintendo DS emulator
LICENSE=	gnu-gpl-v2

BUILD_DIRS=	desmume/src/frontend/libretro
MAKE_FILE=	Makefile.libretro
USE_LANGUAGES=	c c++

LIBRETRO_CORE=	desmume

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
CXXFLAGS+=	-marm
CXXFLAGS+=	-DUSE_POSIX_MEMALIGN -D__RETRO_ARM__
CXXFLAGS+=	-DARM
MAKE_FLAGS+=	DESMUME_JIT=0
MAKE_FLAGS+=	DESMUME_JIT_ARM=1
.elif ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=	DESMUME_JIT=1
.else
MAKE_FLAGS+=	DESMUME_JIT=0
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=../../frontend/libretro/link.T

.include "../../emulators/retroarch/core.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
