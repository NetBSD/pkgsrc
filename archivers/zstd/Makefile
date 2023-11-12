# $NetBSD: Makefile,v 1.50 2023/11/12 21:40:38 nia Exp $

DISTNAME=	zstd-1.5.5
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://facebook.github.io/zstd/
COMMENT=	Fast real-time compression algorithm
LICENSE=	modified-bsd OR gnu-gpl-v2

CHECK_PORTABILITY_SKIP+=	tests/playTests.sh

# 1.4.8
# ld: ../lib/libzstd.a: error adding symbols: no more archived files
# ld:../lib/libzstd.a: file format not recognized; treating as linker script
# ld:../lib/libzstd.a:1: syntax error
# or
# ld: ../lib/libzstd.a: error adding symbols: file format not recognized
# reported as
# https://github.com/facebook/zstd/issues/2453
#MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

# See HASH and BUILD_DIR in lib/Makefile and programs/Makefile.
# Set BUILD_DIR so that HASH is not needed and there is no
# need for coreutils as a dependency.
# HASH is set to false because programs/Makefile try to
# execute HASH in order to see if it exists but the result
# is unused when BUILD_DIR is set.
MAKE_ENV+=		BUILD_DIR=obj
MAKE_ENV+=		HASH=${FALSE:Q}

USE_LANGUAGES=		c c++
USE_TOOLS+=		ggrep gmake pkg-config
PKGCONFIG_OVERRIDE+=	lib/libzstd.pc.in
MAKE_FLAGS=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		INSTALL=${INSTALL:Q}

PTHREAD_OPTS=		optional

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native" && !${MACHINE_PLATFORM:MDarwin-*-powerpc*}
BUILD_TARGET=		lib zstd zlibwrapper
TEST_TARGET=		test
.else
BUILD_TARGET=		lib-nomt zstd zlibwrapper
.endif

.if ${MACHINE_PLATFORM:MDarwin-*-powerpc*}
MAKE_FLAGS+=		LDFLAGS_DYNLIB="-single_module"
MAKE_FLAGS+=		BACKTRACE=0
.endif

# Needed for nanosleep() on Solaris 10, PR pkg/56225
LDFLAGS.SunOS+=		-lrt

BUILDLINK_TRANSFORM.Darwin+=	opt:-shared:-dynamiclib

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
