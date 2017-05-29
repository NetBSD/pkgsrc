# $NetBSD: Makefile,v 1.56 2017/05/29 14:39:28 ryoon Exp $

PKGREVISION=		1
BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

.include "../../meta-pkgs/boost/Makefile.common"

INSTALLATION_DIRS+=	lib

BJAM_ARGS+=		--without-python
PLIST_VARS+=		context fiber log

.if ${OPSYS} == "NetBSD" && ((${MACHINE_ARCH} == "i386") || (!empty(MACHINE_ARCH:Mearm*) && !empty(PKGSRC_COMPILER:Mgcc)))
BJAM_ARGS+=		pch=off
.endif

.if !empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mm68k) || !empty(MACHINE_ARCH:Msparc64)
BJAM_ARGS+=		--without-context
BJAM_ARGS+=		--without-coroutine
BJAM_ARGS+=		--without-coroutine2
.else
PLIST.context=		yes
.endif

# Darwin GCC is unable to build Boost.Log
.if ${OPSYS} == "Darwin" && !empty(PKGSRC_COMPILER:Mgcc)
BJAM_ARGS+=		--without-log
.else
PLIST.log=		yes
.endif

# XXX boost1.64 fiber not building even on netbsd7.99 + gcc5.4
# fiber requires context, so also disable it where context cannot be built
# Additionally fiber checks std::timed_mutex.
#.if ((${OPSYS} == "Darwin" && ${OS_VERSION:R} < 14) || \
#    !empty(MACHINE_PLATFORM:MNetBSD-[0-7]*-*)) || \
#    !empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mm68k) || \
#    !empty(MACHINE_ARCH:Msparc64) || \
#    (${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mclang))
BJAM_ARGS+=		--without-fiber
#.else
#PLIST.fiber=		yes
#.endif

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
