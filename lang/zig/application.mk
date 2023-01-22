# $NetBSD: application.mk,v 1.3 2023/01/22 19:34:22 nikita Exp $
#
# Common logic to handle zig packages
# This is only usable if they include a 'build.zig' file
#
.include "../../mk/bsd.fast.prefs.mk"

# Debug build (default):
# Fast compilation speed, Safety checks enabled, Slow runtime performance
# Large binary size, No reproducible build requirement
# ReleaseFast (-O ReleaseFast)
# Fast runtime performance, Safety checks disabled, Slow compilation speed
# Large binary size, Reproducible build
# ReleaseSafe (-O ReleaseSafe)
# Medium runtime performance, Safety checks enabled, Slow compilation speed
# Large binary size, Reproducible build
# ReleaseSmall (-O ReleaseSmall)
# Medium runtime performance, Safety checks disabled, Slow compilation speed
# Small binary size
ZIGBUILDMODE?=		-Drelease-fast
ZIGBUILDARGS?=
ZIGTESTARGS?=

BUILD_DEPENDS+=		zig-[0-9]*:../../lang/zig
USE_LANGUAGES=		c

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build ${ZIGBUILDMODE} ${ZIGBUILDARGS} --prefix ${DESTDIR}${PREFIX}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build install ${ZIGBUILDMODE} ${ZIGBUILDARGS} --prefix ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} zig build ${ZIGBUILDMODE} ${ZIGBUILDARGS} ${ZIGTESTARGS} test
