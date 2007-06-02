# $NetBSD: bjam.mk,v 1.1.1.1 2007/06/02 17:48:51 jmmv Exp $
#

.include "../../devel/boost-jam/buildlink3.mk"

.include "../../devel/boost-build/toolset.mk"
.include "../../mk/bsd.prefs.mk"

BJAM=			${BUILDLINK_PREFIX.boost-jam}/bin/bjam
BJAM_ARGS+=		--builddir=${WRKSRC}/build
BJAM_ARGS+=		--layout=system
BJAM_ARGS+=		--prefix=${PREFIX}
BJAM_ARGS+=		-sBUILD=${BJAM_BUILD:Q}
BJAM_ARGS+=		-sTOOLS=${BOOST_TOOLSET}
.if ${OPSYS} == "Darwin"
BJAM_ARGS+=		-sTARGET_LIBDIR=${PREFIX}/lib
.endif
.if defined(BOOST_DEBUG) && !empty(BOOST_DEBUG:M[Yy][Ee][Ss])
BJAM_BUILD+=		debug
.endif
BJAM_BUILD+=		<linkflags>${COMPILER_RPATH_FLAG}${PREFIX}/lib
BJAM_BUILD+=		<threading>multi
BJAM_BUILD+=		release
BJAM_CMD=		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_ARGS}

bjam-build:
	@cd ${WRKSRC} && ${BJAM_CMD} stage

bjam-install:
	@cd ${WRKSRC} && ${BJAM_CMD} install
