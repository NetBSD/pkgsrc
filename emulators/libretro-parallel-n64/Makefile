# $NetBSD: Makefile,v 1.2 2020/11/13 16:15:54 nia Exp $

DISTNAME=	libretro-parallel-n64-20200528
CATEGORIES=	emulators
GITHUB_PROJECT=	parallel-n64
GITHUB_TAG=	9dd669e2f63b320c5942f2fe0b2df275dba99393

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/parallel-n64
COMMENT=	Libretro core based on the Parallel N64 emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
LIBRETRO_CORE=	parallel_n64

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=	WITH_DYNAREC=x86
.elif ${MACHINE_ARCH} == "x86_64"
MAKE_FLAGS+=	WITH_DYNAREC=x86_64
.elif ${MACHINE_ARCH} == "aarch64"
MAKE_FLAGS+=	WITH_DYNAREC=aarch64
MAKE_FLAGS+=	HAVE_NEON=0
CFLAGS+=	-DNO_ASM -DARM_FIX
.elif ${MACHINE_ARCH} == "earmv7hf"
MAKE_FLAGS+=	WITH_DYNAREC=arm
MAKE_FLAGS+=	HAVE_NEON=1
CFLAGS+=	-DNO_ASM -DARM_FIX
.elif !empty(MACHINE_ARCH:M*arm*)
MAKE_FLAGS+=	WITH_DYNAREC=arm
MAKE_FLAGS+=	HAVE_NEON=0
CFLAGS+=	-DNO_ASM -DARM_FIX
.else
MAKE_FLAGS+=	WITH_DYNAREC=
CFLAGS+=	-DNO_ASM
.endif

.if ${MACHINE_ARCH} == "powerpc"
.include "../../devel/libatomic/buildlink3.mk"
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./libretro/link.T

.include "options.mk"
.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
