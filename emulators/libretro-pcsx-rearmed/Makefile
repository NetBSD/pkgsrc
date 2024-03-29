# $NetBSD: Makefile,v 1.15 2023/07/21 09:37:18 nia Exp $

DISTNAME=	libretro-pcsx-rearmed-20200526
PKGREVISION=	2
CATEGORIES=	emulators
GITHUB_PROJECT=	pcsx_rearmed
GITHUB_TAG=	7973b25fe929f92e146a854ecaf4f3cea5b4ffb8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/pcsx_rearmed/
COMMENT=	Libretro core based on the PCSX ReARMed emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
MAKE_FILE=	Makefile.libretro

LDFLAGS+=	-lFLAC

MAKE_FLAGS+=	WANT_ZLIB=0 # disable vendored zlib

# lightrec requires stdatomic.h
USE_CC_FEATURES+=	c11

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "earmv7hf"
CFLAGS+=	-march=armv7-a+neon -mfpu=neon
MAKE_FLAGS+=	ARCH=arm
MAKE_FLAGS+=	DYNAREC=ari64
MAKE_FLAGS+=	HAVE_NEON=1
MAKE_FLAGS+=	BUILTIN_GPU=neon
.elif !empty(MACHINE_ARCH:M*arm*)
MAKE_FLAGS+=	ARCH=arm
MAKE_FLAGS+=	DYNAREC=ari64
MAKE_FLAGS+=	HAVE_NEON=0
MAKE_FLAGS+=	BUILTIN_GPU=peops
.else
MAKE_FLAGS+=	DYNAREC=lightrec
MAKE_FLAGS+=	BUILTIN_GPU=peops
.endif

LIBRETRO_CORE=	pcsx_rearmed

.include "../../emulators/retroarch/core.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
