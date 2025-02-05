# $NetBSD: Makefile,v 1.114 2025/02/05 22:14:11 riastradh Exp $

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

PKGREVISION=		1

.include "../../meta-pkgs/boost/Makefile.common"

INSTALLATION_DIRS+=	lib

BJAM_ARGS+=		--without-python
PLIST_VARS+=		backtrace context fiber log longdbl stacktrace_from_exception

.include "../../mk/compiler.mk"

# pch enabled build is generally fragile and breaks with RELRO
BJAM_ARGS+=		pch=off

.if ${MACHINE_ARCH} == alpha || ${MACHINE_ARCH} == m68k || ${MACHINE_ARCH} == sparc64
BJAM_ARGS+=		--without-context
BJAM_ARGS+=		--without-coroutine
BJAM_ARGS+=		--without-fiber
.else
PLIST.context=		yes
.  if !${MACHINE_PLATFORM:MDarwin-1[0-4].*-*}
PLIST.fiber=		yes
.  endif
.endif

.if ${MACHINE_ARCH} == x86_64 && !empty(PKGSRC_COMPILER:Mgcc)
PLIST.stacktrace_from_exception=	yes
.else
BJAM_BUILD+=		boost.stacktrace.from_exception=off
.endif

# Darwin GCC is unable to build Boost.Log
.if ${OPSYS} == "Darwin" && !empty(PKGSRC_COMPILER:Mgcc)
BJAM_ARGS+=		--without-log
.else
PLIST.log=		yes
.endif

# FIXME: other systems might also not support 'long double'
# see patch-boost_math_tools_config.hpp
.if ${OPSYS} != "FreeBSD"
PLIST.longdbl=		yes
.endif

PLIST_VARS+=		stacktrace_addr2line

# XXX In principle addr2line should work just as well in a cross-built
# system as in a natively-built system, but it is detected by a
# run-test and I don't know the boost-jam incantation to override that
# test.  So for now, we'll just omit it.
.if ${USE_CROSS_COMPILE:tl} == "no"
PLIST.stacktrace_addr2line=	yes
.endif

# Add backtrace libs when they got built because of libbacktrace
# being available in the toolchain (not easy to detect beforehand).
GENERATE_PLIST+=	cd ${DESTDIR}/${PREFIX}; \
			for f in lib/libboost_stacktrace_backtrace.*; do \
			if [ -f "$$f" ]; then ${ECHO} "$$f"; fi; \
			done;

UNLIMIT_RESOURCES+=	stacksize

CONFIGURE_ENV+=	BZIP2_INCLUDE=${BUILDLINK_PREFIX.bzip2}/include
CONFIGURE_ENV+=	BZIP2_LIBRARY_PATH=${BUILDLINK_PREFIX.bzip2}/lib
CONFIGURE_ENV+=	ICU_PATH=${BUILDLINK_PREFIX.icu}
CONFIGURE_ENV+=	ZLIB_INCLUDE=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ENV+=	ZLIB_LIBRARY_PATH=${BUILDLINK_PREFIX.zlib}/lib

.include "../../devel/boost-jam/bjam.mk"

do-build: bjam-build

do-install: boost-install-libs boost-install-cmake

PRINT_PLIST_AWK+=	/boost_context/ { $$0 = "$${PLIST.context}"$$0 }
PRINT_PLIST_AWK+=	/boost_coroutine/ { $$0 = "$${PLIST.context}"$$0 }
PRINT_PLIST_AWK+=	/boost_fiber/ { $$0 = "$${PLIST.fiber}"$$0 }
PRINT_PLIST_AWK+=	/boost_log/ { $$0 = "$${PLIST.log}"$$0 }
PRINT_PLIST_AWK+=	/boost_math_c99l/ { $$0 = "$${PLIST.longdbl}"$$0 }
PRINT_PLIST_AWK+=	/boost_math_tr1l/ { $$0 = "$${PLIST.longdbl}"$$0 }
PRINT_PLIST_AWK+=	/boost_stacktrace_from_exception/ { $$0 = "$${PLIST.stacktrace_from_exception}"$$0 }

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
