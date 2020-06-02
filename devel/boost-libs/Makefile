# $NetBSD: Makefile,v 1.82 2020/06/02 08:23:34 adam Exp $

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

.if (${OPSYS} == "NetBSD" && \
	((${MACHINE_ARCH} == "i386") || \
	(!empty(MACHINE_ARCH:Mearm*) && !empty(PKGSRC_COMPILER:Mgcc)))) || \
    (!empty(MACHINE_PLATFORM:MNetBSD-8.*-x86_64) && \
	!empty(CC_VERSION:Mgcc-7.*))
BJAM_ARGS+=		pch=off
.endif

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
.if ${OPSYS} != "FreeBSD"
PLIST.longdbl=		yes
.endif

# libboost_stacktrace_backtrace requires libbacktrace.
# FIXME: The condition needs to be refined for non-Debian/Ubuntu
# platforms shipped with libbacktrace.
.if ${OPSYS} == "Linux" && (exists(/etc/debian_version) || exists(/etc/devuan_version))
PLIST.backtrace=	yes
.endif

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
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
