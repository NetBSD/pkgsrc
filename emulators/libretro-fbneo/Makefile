# $NetBSD: Makefile,v 1.4 2023/05/29 14:33:14 nia Exp $

FBNEO_TAG=	98e3e5eba0f45cce06c11cc7f9065ddb23ece3e1
DISTNAME=	FBNeo-${FBNEO_TAG}
PKGNAME=	libretro-fbneo-20230524
CATEGORIES=	emulators
GITHUB_PROJECT=	FBNeo
MASTER_SITES=	https://git.libretro.com/libretro/FBNeo/-/archive/${FBNEO_TAG}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.libretro.com/libretro/FBNeo/-/tree/master/src/burner/libretro
COMMENT=	Libretro core based on the FinalBurn Neo arcade game emulator
LICENSE=	fbalpha-license

SUPERSEDES+=	libretro-fbalpha-[0-9]*

UNLIMIT_RESOURCES+=	datasize virtualsize

BUILD_DIRS=	src/burner/libretro
USE_LANGUAGES=	c c++

LIBRETRO_CORE=	fbneo

MAKE_FLAGS+=	EXTERNAL_ZLIB=1

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "earmv6hf" || ${MACHINE_ARCH} == "earmv7hf"
MAKE_FLAGS+=	USE_CYCLONE=1
MAKE_FLAGS+=	ENDIANNESS_DEFINES=-DLSB_FIRST
.elif ${MACHINE_ARCH} == "aarch64"
MAKE_FLAGS+=	ENDIANNESS_DEFINES=-DLSB_FIRST
.elif ${MACHINE_ARCH} == "x86_64"
MAKE_FLAGS+=	USE_X64_DRC=1
MAKE_FLAGS+=	ENDIANNESS_DEFINES=-DLSB_FIRST
.elif ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=	ENDIANNESS_DEFINES=-DLSB_FIRST
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=../../burner/libretro/link.T

.include "../../emulators/retroarch/core.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
