# $NetBSD: application.mk,v 1.2 2023/01/19 20:46:22 nikita Exp $
#
# Common logic to handle zig packages
# This is only usable if they include a 'build.zig' file
#
.include "../../mk/bsd.fast.prefs.mk"

ZIGBUILDARGS?=		-Drelease-fast

BUILD_DEPENDS+=		zig-[0-9]*:../../lang/zig
USE_LANGUAGES=		c

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build ${ZIGBUILDARGS} --prefix ${DESTDIR}${PREFIX}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build install ${ZIGBUILDARGS} --prefix ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} zig build test
