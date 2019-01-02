# $NetBSD: Makefile,v 1.1 2019/01/02 13:24:29 nia Exp $

DISTNAME=	libretro-mame2010-20180417
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	mame2010-libretro
GITHUB_TAG=	70732f9137f6bb2bde4014746ea8bc613173dd1e

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/mame_2010/
COMMENT=	Libretro core based on the MAME 0.139 arcade game emulator
LICENSE=	mame-license

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	platform=unix
MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"
MAKE_FLAGS+=	BUILD_ZLIB=0

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Bitrig"
CFLAGS+=	-DSDLMAME_BSD
.endif

.if ${OPSYS} != "Linux"
CFLAGS+=	-DNO_AFFINITY_NP
.endif

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

MAKE_FLAGS+=	CC=${CXX:Q}
MAKE_FLAGS+=	LD=${CXX:Q}

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mame2010_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mame2010_libretro.so

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
