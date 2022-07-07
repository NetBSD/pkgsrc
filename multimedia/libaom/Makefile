# $NetBSD: Makefile,v 1.24 2022/07/07 10:13:56 adam Exp $

DISTNAME=	libaom-3.4.0
CATEGORIES=	multimedia
MASTER_SITES=	https://storage.googleapis.com/aom-releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aomedia.googlesource.com/aom/
COMMENT=	Library for using AV1, video coding format
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

SUBST_CLASSES+=		version
SUBST_FILES.version=	build/cmake/version.cmake
SUBST_STAGE.version=	pre-configure
SUBST_VARS.version=	PKGVERSION_NOREV

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	../
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DCMAKE_COLOR_MAKEFILE:BOOL=ON
CMAKE_ARGS+=	-DENABLE_DECODE_PERF_TESTS:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_EXAMPLES:BOOL=ON
CMAKE_ARGS+=	-DENABLE_DOCS:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_GOMA:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_TESTS:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_TOOLS:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_WERROR:BOOL=OFF

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*) \
  || !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64*) \
  || !empty(MACHINE_PLATFORM:MDarwin-*-aarch64)
CMAKE_ARGS+=	-DCONFIG_RUNTIME_CPU_DETECT=0
.endif

.if !empty(MACHINE_ARCH:Mmips64*)
CMAKE_ARGS+=	-DAOM_TARGET_CPU="mips64"
.elif !empty(MACHINE_ARCH:Mmips*)
CMAKE_ARGS+=	-DAOM_TARGET_CPU="mips"
.elif !empty(MACHINE_ARCH:Mpowerpc*)
CMAKE_ARGS+=	-DAOM_TARGET_CPU="ppc"
.elif ${MACHINE_ARCH} == "earmv7hf"
CFLAGS+=	-mfpu=neon
CMAKE_ARGS+=	-DAOM_TARGET_CPU="armv7"
.elif ${MACHINE_ARCH} == "aarch64"
CMAKE_ARGS+=	-DAOM_TARGET_CPU="arm64"
.elif ${MACHINE_ARCH} == "x86_64"
CMAKE_ARGS+=	-DAOM_TARGET_CPU="x86_64"
.elif ${MACHINE_ARCH} == "i386"
CMAKE_ARGS+=	-DAOM_TARGET_CPU="x86"
.else
CMAKE_ARGS+=	-DAOM_TARGET_CPU="generic"
.endif

.if ${MACHINE_ARCH} == x86_64 || ${MACHINE_ARCH} == i386
CMAKE_ARGS+=	-DENABLE_NASM:BOOL=ON
TOOL_DEPENDS+=	nasm>=2.13:../../devel/nasm
.endif

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		build/aom.pc

.include "../../mk/bsd.pkg.mk"
