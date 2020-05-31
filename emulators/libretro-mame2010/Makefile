# $NetBSD: Makefile,v 1.4 2020/05/31 18:34:56 nia Exp $

DISTNAME=	libretro-mame2010-20200525
CATEGORIES=	emulators
GITHUB_PROJECT=	mame2010-libretro
GITHUB_TAG=	bef96188e7276422eab81b44b41361896885bae5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/mame_2010/
COMMENT=	Libretro core based on the MAME 0.139 arcade game emulator
LICENSE=	mame-license

USE_LANGUAGES=	c c++

LIBRETRO_CORE=	mame2010

MAKE_FLAGS+=	BUILD_ZLIB=0

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
CFLAGS+=	-DSDLMAME_BSD
.endif

.if ${OPSYS} != "Linux"
CFLAGS+=	-DNO_AFFINITY_NP
.endif

CFLAGS+=	-Wno-narrowing

.if ${MACHINE_ARCH} != "x86_64" && ${MACHINE_ARCH} != "i386"
MAKE_FLAGS+=	FORCE_DRC_C_BACKEND=1
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_FLAGS+=	NATIVECC=${NATIVE_CXX:Q}
MAKE_FLAGS+=	NATIVELD=${NATIVE_CXX:Q}
.else
MAKE_FLAGS+=	NATIVECC=${CXX:Q}
MAKE_FLAGS+=	NATIVELD=${CXX:Q}
.endif

.for platform in ${LP64PLATFORMS}
.  if ${MACHINE_PLATFORM:M${platform}}
MAKE_FLAGS+=	PTR64=1
.  endif
.endfor

.include "../../emulators/retroarch/core.mk"

MAKE_FLAGS+=	CC=${CXX:Q}
MAKE_FLAGS+=	LD=${CXX:Q}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
