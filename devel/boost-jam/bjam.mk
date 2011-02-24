# $NetBSD: bjam.mk,v 1.9 2011/02/24 11:05:35 adam Exp $

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
