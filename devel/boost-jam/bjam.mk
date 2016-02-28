# $NetBSD: bjam.mk,v 1.17 2016/02/28 23:54:11 minskim Exp $

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

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mgcc)
.  if !empty(CC_VERSION:Mgcc-4.[4-7]*)
BJAM_ARGS+=		cxxflags=-std=c++0x
CXXFLAGS+=		-std=c++0x
.  elif !empty(CC_VERSION:Mgcc-4.[89]*)
BJAM_ARGS+=		cxxflags=-std=c++11
CXXFLAGS+=		-std=c++11
.  elif !empty(CC_VERSION:Mgcc-5.[0-9]*)
BJAM_ARGS+=		cxxflags=-std=c++14
CXXFLAGS+=		-std=c++14
.  endif
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
BJAM_ARGS+=		cxxflags=-std=c++11
CXXFLAGS+=		-std=c++11
.  if !empty(OPSYS:MDarwin)
BJAM_ARGS+=		cxxflags=-stdlib=libc++ linkflags=-stdlib=libc++
.  endif
.endif

BJAM_BUILD+=		variant=release
BJAM_BUILD+=		threading=multi
BJAM_BUILD+=		link=shared,static

BJAM_CMD=		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_ARGS}

UNLIMIT_RESOURCES+=	datasize

bjam-build:
	${_ULIMIT_CMD} \
	cd ${WRKSRC} && ${BJAM_CMD} --prefix=${PREFIX} stage

bjam-install:
	${_ULIMIT_CMD} \
	cd ${WRKSRC} && ${BJAM_CMD} --prefix=${DESTDIR}${PREFIX} install
