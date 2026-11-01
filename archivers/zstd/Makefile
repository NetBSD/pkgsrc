# $NetBSD: Makefile,v 1.54 2026/11/01 13:07:16 wiz Exp $

PKGREVISION=	1

.include "Makefile.common"

COMMENT=	Fast real-time compression algorithm

# See HASH and BUILD_DIR in lib/Makefile and programs/Makefile.
# Set BUILD_DIR so that HASH is not needed and there is no
# need for coreutils as a dependency.
# HASH is set to false because programs/Makefile try to
# execute HASH in order to see if it exists but the result
# is unused when BUILD_DIR is set.
MAKE_ENV+=		BUILD_DIR=obj
MAKE_ENV+=		HASH=${FALSE:Q}

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	lib/libzstd.pc.in
MAKE_FLAGS=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		INSTALL=${INSTALL:Q}

PTHREAD_OPTS=		optional

.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native" && !${MACHINE_PLATFORM:MDarwin-*-powerpc*}
BUILD_TARGET=		lib zstd
TEST_TARGET=		test
.else
BUILD_TARGET=		lib-nomt zstd
.endif

.if ${MACHINE_PLATFORM:MDarwin-*-powerpc*}
MAKE_FLAGS+=		LDFLAGS_DYNLIB="-single_module"
MAKE_FLAGS+=		BACKTRACE=0
.endif

# Needed for nanosleep() on Solaris 10, PR pkg/56225
LDFLAGS.SunOS+=		-lrt

BUILDLINK_TRANSFORM.Darwin+=	opt:-shared:-dynamiclib

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/zstdgrep
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/zstdgrep.1

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
