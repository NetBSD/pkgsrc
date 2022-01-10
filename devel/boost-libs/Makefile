# $NetBSD: Makefile,v 1.93 2022/01/10 01:23:31 ryoon Exp $

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

.include "../../meta-pkgs/boost/Makefile.common"

INSTALLATION_DIRS+=	lib

BJAM_ARGS+=		--without-python
PLIST_VARS+=		backtrace context fiber log longdbl

.include "../../mk/compiler.mk"

# pch enabled build is generally fragile and breaks with RELRO
BJAM_ARGS+=		pch=off

.if !empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mm68k) || !empty(MACHINE_ARCH:Msparc64)
BJAM_ARGS+=		--without-context
BJAM_ARGS+=		--without-coroutine
BJAM_ARGS+=		--without-fiber
.else
PLIST.context=		yes
.  if !(${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mgcc)) && \
    empty(MACHINE_PLATFORM:MDarwin-1[0-4].*-*)
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
.if ${OPSYS} != "FreeBSD" && ${OPSYS} != "NetBSD"
PLIST.longdbl=		yes
.endif

# Add backtrace libs when they got built because of libbacktrace
# being available in the toolchain (not easy to detect beforehand).
GENERATE_PLIST+=	cd ${DESTDIR:Q}/${PREFIX:Q}; \
  for f in lib/libboost_stacktrace_backtrace.*; do \
   if [ -f "$$f" ]; then echo "$$f"; fi; \
  done;

UNLIMIT_RESOURCES+=	stacksize

MAKE_ENV+=	BZIP2_INCLUDE=${BUILDLINK_PREFIX.bzip2}/include
MAKE_ENV+=	BZIP2_LIBPATH=${BUILDLINK_PREFIX.bzip2}/lib
MAKE_ENV+=	EXPAT_INCLUDE=${BUILDLINK_PREFIX.expat}/include
MAKE_ENV+=	EXPAT_LIBPATH=${BUILDLINK_PREFIX.expat}/lib
MAKE_ENV+=	ICU_PATH=${BUILDLINK_PREFIX.icu}
MAKE_ENV+=	ZLIB_INCLUDE=${BUILDLINK_PREFIX.zlib}/include
MAKE_ENV+=	ZLIB_LIBPATH=${BUILDLINK_PREFIX.zlib}/lib

.include "../../devel/boost-jam/bjam.mk"

do-build: bjam-build

do-install: boost-install-libs

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
