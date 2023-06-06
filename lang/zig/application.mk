# $NetBSD: application.mk,v 1.6 2023/06/06 12:41:47 riastradh Exp $
#
# Common logic to handle zig packages
# This is only usable if they include a 'build.zig' file
#
.include "../../mk/bsd.fast.prefs.mk"

# https://github.com/ziglang/zig/issues/3382
# For now, Zig doesn't support CFLAGS/LDFLAGS/etc.

# Debug build (default):
# Fast compilation speed, Safety checks enabled, Slow runtime performance
# Large binary size, No reproducible build requirement
# ReleaseFast (-Drelease-fast)
# Fast runtime performance, Safety checks disabled, Slow compilation speed
# Large binary size, Reproducible build
# ReleaseSafe (-Drelease-safe=true)
# Medium runtime performance, Safety checks enabled, Slow compilation speed
# Large binary size, Reproducible build
# ReleaseSmall (-Drelease-small=true)
# Medium runtime performance, Safety checks disabled, Slow compilation speed
# Small binary size
ZIGBUILDMODE?=		-Drelease-safe=true
ZIGCPUMODE?=		-Dcpu=baseline
ZIGBUILDARGS?=
ZIGTESTARGS?=

TOOL_DEPENDS+=		zig-[0-9]*:../../lang/zig
USE_LANGUAGES=		c

#MAKE_ENV+=		ZIG_GLOBAL_CACHE_DIR=${WRKSRC}/tmp
# \todo: There is currently an issue building zig packages as RELRO.
#RELRO_SUPPORTED=	no

# figure out how to do this for all zig packages:
#ZIGBUILDARGS+=		-Dpie=true
#.if ${MKDEBUG:Uyes:M[yY][eE][sS]} && ${INSTALL_UNSTRIPPED:Uyes:tl} == yes
#ZIGBUILDARGS+=		-Dstrip=true
#.endif

do-build:
	mkdir ${WRKSRC}/tmp
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build ${ZIGBUILDMODE} ${ZIGCPUMODE} ${ZIGBUILDARGS} --prefix ${DESTDIR}${PREFIX}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build install ${ZIGBUILDMODE} ${ZIGCPUMODE} ${ZIGBUILDARGS} --prefix ${DESTDIR}${PREFIX}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} zig build ${ZIGBUILDMODE} ${ZIGBUILDARGS} ${ZIGCPUMODE} ${ZIGTESTARGS} test
