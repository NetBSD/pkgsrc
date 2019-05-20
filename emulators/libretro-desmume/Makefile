# $NetBSD: Makefile,v 1.10 2019/05/20 10:32:32 nia Exp $

DISTNAME=	libretro-desmume-20190426
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	desmume
GITHUB_TAG=	3069551c2e1de633c333739cca8bb7108ca3d3e9

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/desmume/
COMMENT=	Libretro core based on the DeSmuME Nintendo DS emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
BUILD_DIRS=	desmume/src/frontend/libretro
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake
USE_LANGUAGES=	c99 gnu++11

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
CXXFLAGS+=	-marm
CXXFLAGS+=	-DUSE_POSIX_MEMALIGN -D__RETRO_ARM__
CXXFLAGS+=	-DARM
MAKE_FLAGS+=	DESMUME_JIT=0
MAKE_FLAGS+=	DESMUME_JIT_ARM=1
.elif ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=	DESMUME_JIT=1
.else
MAKE_FLAGS+=	DESMUME_JIT=0
.endif

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=../../frontend/libretro/link.T

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} \
	    ${WRKSRC}/desmume/src/frontend/libretro/desmume_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/desmume_libretro.so

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
