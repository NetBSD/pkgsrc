# $NetBSD: Makefile,v 1.6 2018/08/12 17:11:39 nia Exp $

DISTNAME=	libretro-picodrive-20180722
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	picodrive
GITHUB_TAG=	2db90628f5f29f1d4030172ce4f57ab757fa9d93

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/picodrive/
COMMENT=	Fast MegaDrive/MegaCD/32X emulator
LICENSE=	mame-license

EXTRACT_USING=	bsdtar
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/bsd.prefs.mk"

NOT_FOR_PLATFORM=	${BIGENDIANPLATFORMS}

.if !empty(MACHINE_ARCH:M*armv7*)
# Avoid mixing in Thumb code with Picodrive's ARM asm.
CFLAGS+=		-marm
BUILD_MAKE_FLAGS+=	ARCH=arm
BUILD_MAKE_FLAGS+=	ARM_ASM=1
BUILD_MAKE_FLAGS+=	use_cyclone=0
BUILD_MAKE_FLAGS+=	use_fame=1
BUILD_MAKE_FLAGS+=	use_drz80=0
BUILD_MAKE_FLAGS+=	use_cz80=1
BUILD_MAKE_FLAGS+=	use_sh2drc=1
BUILD_MAKE_FLAGS+=	use_svpdrc=1
.elif !empty(MACHINE_ARCH:M*armv6*)
CFLAGS+=		-marm
BUILD_MAKE_FLAGS+=	ARCH=arm
BUILD_MAKE_FLAGS+=	ARM_ASM=1
BUILD_MAKE_FLAGS+=	asm_memory=1
BUILD_MAKE_FLAGS+=	asm_render=1
BUILD_MAKE_FLAGS+=	asm_ym2612=1
BUILD_MAKE_FLAGS+=	asm_misc=1
BUILD_MAKE_FLAGS+=	asm_cdpico=1
BUILD_MAKE_FLAGS+=	asm_cdmemory=1
BUILD_MAKE_FLAGS+=	asm_mix=1
BUILD_MAKE_FLAGS+=	use_cyclone=0
BUILD_MAKE_FLAGS+=	use_fame=0
BUILD_MAKE_FLAGS+=	use_drz80=1
BUILD_MAKE_FLAGS+=	use_cz80=0
BUILD_MAKE_FLAGS+=	use_sh2drc=1
BUILD_MAKE_FLAGS+=	use_svpdrc=1
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/picodrive_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/picodrive_libretro.so

.include "../../mk/bsd.pkg.mk"
