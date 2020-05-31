# $NetBSD: Makefile,v 1.7 2020/05/31 18:51:00 nia Exp $

PKGNAME=	libretro-ppsspp-1.7.5
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
ARMIPS_TAG=	9efe3367284d2d1eeb14fc302a2c12c36e3e255e
GLSLANG_TAG=	29619b2312f7bc862221749f3f4d37c3e6a0dee2
SPRIV_TAG=	be7425ef70231ab82930331959ab487d605d0482

SITES.ppsspp.tar.gz= \
	-https://github.com/hrydgard/ppsspp/archive/v${PKGVERSION_NOREV}.tar.gz

SITES.ppsspp-armips.tar.gz= \
	-https://github.com/Kingcom/armips/archive/${ARMIPS_TAG}.tar.gz

SITES.ppsspp-glslang.tar.gz= \
	-https://github.com/hrydgard/glslang/archive/${GLSLANG_TAG}.tar.gz

SITES.ppsspp-spriv.tar.gz= \
	-https://github.com/KhronosGroup/SPIRV-Cross/archive/${SPRIV_TAG}.tar.gz

WRKSRC=		${WRKDIR}/ppsspp-${PKGVERSION_NOREV}
BUILD_DIRS=	libretro

USE_LANGUAGES=	c c++11

LIBRETRO_CORE=	ppsspp

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

LDFLAGS+=		${BUILDLINK_LDADD.libexecinfo}

post-extract:
	${MV} ${WRKDIR}/armips-${ARMIPS_TAG}/* ${WRKSRC}/ext/armips
	${MV} ${WRKDIR}/glslang-${GLSLANG_TAG}/* ${WRKSRC}/ext/glslang
	${MV} ${WRKDIR}/SPIRV-Cross-${SPRIV_TAG}/* ${WRKSRC}/ext/SPIRV-Cross

.include "options.mk"
.include "../../emulators/retroarch/core.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
