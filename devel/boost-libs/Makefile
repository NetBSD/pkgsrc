# $NetBSD: Makefile,v 1.105 2024/05/29 16:31:58 adam Exp $

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

PKGREVISION= 1
.include "../../meta-pkgs/boost/Makefile.common"

INSTALLATION_DIRS+=	lib

BJAM_ARGS+=		--without-python
PLIST_VARS+=		backtrace context fiber log longdbl

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

# Add backtrace libs when they got built because of libbacktrace
# being available in the toolchain (not easy to detect beforehand).
GENERATE_PLIST+=	cd ${DESTDIR}/${PREFIX}; \
			for f in lib/libboost_stacktrace_backtrace.*; do \
			if [ -f "$$f" ]; then echo "$$f"; fi; \
			done;

UNLIMIT_RESOURCES+=	stacksize

CONFIGURE_ENV+=	BZIP2_INCLUDE=${BUILDLINK_PREFIX.bzip2}/include
CONFIGURE_ENV+=	BZIP2_LIBRARY_PATH=${BUILDLINK_PREFIX.bzip2}/lib
CONFIGURE_ENV+=	ICU_PATH=${BUILDLINK_PREFIX.icu}
CONFIGURE_ENV+=	ZLIB_INCLUDE=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ENV+=	ZLIB_LIBRARY_PATH=${BUILDLINK_PREFIX.zlib}/lib

.include "../../devel/boost-jam/bjam.mk"

do-build: bjam-build

do-install: boost-install-libs

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
