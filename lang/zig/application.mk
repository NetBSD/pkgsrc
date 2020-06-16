# $NetBSD: application.mk,v 1.1 2020/06/16 11:01:42 nikita Exp $
#
# Common logic to handle zig packages
# This is only usable if they include a 'build.zig' file
#
.include "../../mk/bsd.fast.prefs.mk"

_ZIGBUILDINSTALLARGS=	-Drelease-fast --prefix ${DESTDIR}${PREFIX}

BUILD_DEPENDS+=		zig-[0-9]*:../../lang/zig
USE_LANGUAGES=		c

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build ${_ZIGBUILDINSTALLARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build install ${_ZIGBUILDINSTALLARGS}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} zig build test
