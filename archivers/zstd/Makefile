# $NetBSD: Makefile,v 1.44 2022/01/19 06:02:25 adam Exp $

DISTNAME=	zstd-1.5.1
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
MAKE_ENV+=		HASH=${FALSE}

USE_LANGUAGES=		c c++
USE_TOOLS+=		ggrep gmake pkg-config
PKGCONFIG_OVERRIDE+=	lib/libzstd.pc.in
MAKE_FLAGS=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		INSTALL=${INSTALL:Q}

BUILD_TARGET=		allmost
TEST_TARGET=		test

# Needed for nanosleep() on Solaris 10, PR pkg/56225
LDFLAGS.SunOS+=		-lrt

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
