# $NetBSD: Makefile,v 1.3 2020/08/11 18:47:39 joerg Exp $

DISTNAME=	libretro-fbneo-20200530
CATEGORIES=	emulators
GITHUB_PROJECT=	FBNeo
GITHUB_TAG=	301cf7b6eeb3e7683952b98b66f39008f580b26d

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/FBNeo/tree/master/src/burner/libretro
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
.elif ${MACHINE_ARCH} == "x86_64"
MAKE_FLAGS+=	USE_X64_DRC=1
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=../../burner/libretro/link.T

.include "../../emulators/retroarch/core.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
