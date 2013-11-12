# $NetBSD: bjam.mk,v 1.14 2013/11/12 16:49:07 adam Exp $

.include "../../devel/boost-jam/buildlink3.mk"

.include "../../devel/boost-build/toolset.mk"
.include "../../mk/bsd.prefs.mk"

BJAM=			${BUILDLINK_PREFIX.boost-jam}/bin/bjam

.if !empty(MAKE_JOBS)
BJAM_ARGS+=		-j${MAKE_JOBS}
.endif
BJAM_ARGS+=		--builddir=${WRKSRC}/build
BJAM_ARGS+=		--layout=system
BJAM_ARGS+=		--toolset=${BOOST_TOOLSET}
BJAM_ARGS+=		--disable-long-double
BJAM_ARGS+=		${BJAM_BUILD}
# GCC 4.4 and above needs this
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[4-9]*)
BJAM_ARGS+=		cxxflags=-std=c++0x
.endif
#
.if !empty(PKGSRC_COMPILER:Mclang)
BJAM_ARGS+=		cxxflags=-std=c++11
.  if !empty(OPSYS:MDarwin)
BJAM_ARGS+=		cxxflags=-stdlib=libc++ linkflags=-stdlib=libc++
.  endif
.endif

BJAM_BUILD+=		release
BJAM_BUILD+=		threading=multi
BJAM_BUILD+=		link=shared,static

BJAM_CMD=		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_ARGS}

.include "../../meta-pkgs/boost/options.mk"

UNLIMIT_RESOURCES+=	datasize

bjam-build:
	${_ULIMIT_CMD}							\
	cd ${WRKSRC} && ${BJAM_CMD} --prefix=${PREFIX} stage

bjam-install:
	${_ULIMIT_CMD}							\
	cd ${WRKSRC} && ${BJAM_CMD} --prefix=${DESTDIR}${PREFIX} install
