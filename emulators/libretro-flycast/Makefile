# $NetBSD: Makefile,v 1.3 2020/05/31 17:38:15 nia Exp $

DISTNAME=	libretro-flycast-20200529
CATEGORIES=	emulators
GITHUB_PROJECT=	flycast
GITHUB_TAG=	e595af5dfbff2e49fbcb95bec5b240785c8b4f4f

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/flycast/
COMMENT=	Libretro core based on the Flycast Sega Dreamcast emulator
LICENSE=	gnu-gpl-v2

SUPERSEDES+=	libretro-reicast-[0-9]*

LIBRETRO_CORE=	flycast
USE_LANGUAGES=	c c++

LDFLAGS+=	-lFLAC -lxxhash -lz

MAKE_FLAGS+=	HAVE_OPENMP=0
MAKE_FLAGS+=	HAVE_VULKAN=0
MAKE_FLAGS+=	SINGLE_PREC_FLAGS=1
MAKE_FLAGS+=	CC_AS=${AS}

.if ${MACHINE_ARCH} != "x86_64"
CFLAGS+=	-DLOW_END
CXXFLAGS+=	-DLOW_END
.endif

CFLAGS+=	-DHAVE_POSIX_MEMALIGN=1
CXXFLAGS+=	-DHAVE_POSIX_MEMALIGN=1

.if ${MACHINE_ARCH} == "aarch64"
MAKE_FLAGS+=	WITH_DYNAREC=arm64
MAKE_FLAGS+=	HAVE_GENERIC_JIT=0
.elif ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=	WITH_DYNAREC=x86
MAKE_FLAGS+=	HAVE_GENERIC_JIT=0
.elif ${MACHINE_ARCH} == "x86_64"
MAKE_FLAGS+=	WITH_DYNAREC=x86_64
MAKE_FLAGS+=	HAVE_GENERIC_JIT=0
.elif ${MACHINE_ARCH} == "earmv7hf"
MAKE_FLAGS+=	WITH_DYNAREC=arm
MAKE_FLAGS+=	HAVE_GENERIC_JIT=0
MAKE_FLAGS+=	ARM_FLOAT_ABI_HARD=1
MAKE_FLAGS+=	ARMV7A_FLAGS=1
.elif ${MACHINE_ARCH} == "earmv6hf"
CFLAGS+=	-marm
CXXFLAGS+=	-marm
MAKE_FLAGS+=	WITH_DYNAREC=arm
MAKE_FLAGS+=	HAVE_GENERIC_JIT=0
MAKE_FLAGS+=	ARM_FLOAT_ABI_HARD=1
.elif !empty(MACHINE_ARCH:M*arm*)
CFLAGS+=	-marm
CXXFLAGS+=	-marm
MAKE_FLAGS+=	WITH_DYNAREC=arm
MAKE_FLAGS+=	HAVE_GENERIC_JIT=0
MAKE_FLAGS+=	ARM_FLOAT_ABI_HARD=0
.elif !empty(MACHINE_ARCH:M*mips*)
MAKE_FLAGS+=	WITH_DYNAREC=mips
MAKE_FLAGS+=	HAVE_GENERIC_JIT=0
.else
MAKE_FLAGS+=	WITH_DYNAREC=
MAKE_FLAGS+=	HAVE_GENERIC_JIT=1
.endif

.include "options.mk"
.include "../../emulators/retroarch/core.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
