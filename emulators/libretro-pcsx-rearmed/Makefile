# $NetBSD: Makefile,v 1.12 2020/06/01 17:41:02 nia Exp $

DISTNAME=	libretro-pcsx-rearmed-20200526
PKGREVISION=	1
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

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "earmv7hf"
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
