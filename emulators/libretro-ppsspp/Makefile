# $NetBSD: Makefile,v 1.2 2018/11/23 08:06:30 ryoon Exp $

PKGNAME=	libretro-ppsspp-1.6.3
PKGREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/ppsspp/
COMMENT=	Libretro core based on the PPSSPP PlayStation Portable emulator
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	ppsspp-${PKGVERSION_NOREV}
DISTFILES+=	ppsspp.tar.gz
DISTFILES+=	ppsspp-armips.tar.gz
DISTFILES+=	ppsspp-glslang.tar.gz
DISTFILES+=	ppsspp-spriv.tar.gz

# Submodules
ARMIPS_TAG=	8b4cadaf62d7de42d374056fc6aafc555f2bc7dc
GLSLANG_TAG=	2edde6665d9a56ead5ea0e55b4e64d9a803e6164
SPRIV_TAG=	90966d50f57608587bafd95b4e345b02b814754a

SITES.ppsspp.tar.gz= \
    -https://github.com/hrydgard/ppsspp/archive/v${PKGVERSION_NOREV}.tar.gz

SITES.ppsspp-armips.tar.gz= \
    -https://github.com/Kingcom/armips/archive/${ARMIPS_TAG}.tar.gz

SITES.ppsspp-glslang.tar.gz= \
    -https://github.com/hrydgard/glslang/archive/${GLSLANG_TAG}.tar.gz

SITES.ppsspp-spriv.tar.gz= \
    -https://github.com/KhronosGroup/SPIRV-Cross/archive/${SPRIV_TAG}.tar.gz

EXTRACT_USING=	bsdtar
WRKSRC=		${WRKDIR}/ppsspp-${PKGVERSION_NOREV}
BUILD_DIRS=	libretro

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++11

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	*-*-*arm* *-*-x86_64 *-*-i386

.if !empty(MACHINE_ARCH:M*arm*)
CFLAGS+=		-marm
MAKE_FLAGS+=		TARGET_ARCH=arm
.elif ${MACHINE_ARCH} == "x86_64"
MAKE_FLAGS+=		TARGET_ARCH=x86_64
.elif ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=		TARGET_ARCH=x86
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

post-extract:
	${MV} ${WRKDIR}/armips-${ARMIPS_TAG}/* ${WRKSRC}/ext/armips
	${MV} ${WRKDIR}/glslang-${GLSLANG_TAG}/* ${WRKSRC}/ext/glslang
	${MV} ${WRKDIR}/SPIRV-Cross-${SPRIV_TAG}/* ${WRKSRC}/ext/SPIRV-Cross

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/ppsspp_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/ppsspp_libretro.so

.include "options.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
