# $NetBSD: Makefile,v 1.3 2018/09/27 20:22:26 tnn Exp $

DISTNAME=	libretro-desmume-20180807
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	desmume
GITHUB_TAG=	f546d2dd15c8c8c44907e4332339c36d9f8319d5

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/desmume/
COMMENT=	Libretro core based on the Desmume Nintendo DS emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
BUILD_DIRS=	desmume/src/frontend/libretro
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

CXXFLAGS+=	-D__STDC_FORMAT_MACROS
.if !empty(MACHINE_ARCH:M*arm*)
CXXFLAGS+=		-marm
CXXFLAGS+=		-DUSE_POSIX_MEMALIGN -D__RETRO_ARM__
CXXFLAGS+=		-DARM
MAKE_FLAGS+=		DESMUME_JIT=0
MAKE_FLAGS+=		DESMUME_JIT_ARM=1
.elif ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=		DESMUME_JIT=1
.else
MAKE_FLAGS+=		DESMUME_JIT=0
.endif

MAKE_FLAGS+=		GIT_VERSION="-pkgsrc"
INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} \
	    ${WRKSRC}/desmume/src/frontend/libretro/desmume_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/desmume_libretro.so

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
