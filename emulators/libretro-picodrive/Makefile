# $NetBSD: Makefile,v 1.10 2020/06/02 14:51:03 nia Exp $

DISTNAME=	libretro-picodrive-20200527
PKGREVISION=	1
CATEGORIES=	emulators
GITHUB_PROJECT=	picodrive
GITHUB_TAG=	b8fb8f285317632f42ecbbd36cf4fe18ea9189f1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/picodrive/
COMMENT=	Libretro core based on the Picodrive MegaDrive/MegaCD/32X emulator
LICENSE=	mame-license

MAKE_FILE=	Makefile.libretro

.include "../../mk/bsd.prefs.mk"

NOT_FOR_PLATFORM=	${BIGENDIANPLATFORMS}

.if ${MACHINE_ARCH} == "earmv7hf"
# Avoid mixing in Thumb code with Picodrive's ARM asm.
CFLAGS+=	-marm
MAKE_FLAGS+=	ARCH=arm
MAKE_FLAGS+=	ARM_ASM=1
MAKE_FLAGS+=	use_cyclone=0
MAKE_FLAGS+=	use_fame=1
MAKE_FLAGS+=	use_drz80=0
MAKE_FLAGS+=	use_cz80=1
MAKE_FLAGS+=	use_sh2drc=1
MAKE_FLAGS+=	use_svpdrc=1
.elif ${MACHINE_ARCH} == "earmv6hf"
CFLAGS+=	-marm
MAKE_FLAGS+=	ARCH=arm
MAKE_FLAGS+=	ARM_ASM=1
MAKE_FLAGS+=	asm_memory=1
MAKE_FLAGS+=	asm_render=1
MAKE_FLAGS+=	asm_ym2612=1
MAKE_FLAGS+=	asm_misc=1
MAKE_FLAGS+=	asm_cdpico=1
MAKE_FLAGS+=	asm_cdmemory=1
MAKE_FLAGS+=	asm_mix=1
MAKE_FLAGS+=	use_cyclone=0
MAKE_FLAGS+=	use_fame=0
MAKE_FLAGS+=	use_drz80=1
MAKE_FLAGS+=	use_cz80=0
MAKE_FLAGS+=	use_sh2drc=1
MAKE_FLAGS+=	use_svpdrc=1
.endif

LIBRETRO_CORE=	picodrive

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
