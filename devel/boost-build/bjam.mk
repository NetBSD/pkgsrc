# $NetBSD: bjam.mk,v 1.2 2005/03/25 12:45:09 jmmv Exp $
#

.include "../../devel/boost-build/buildlink3.mk"

.include "toolset.mk"
.include "../../mk/bsd.prefs.mk"

BJAM=			${BUILDLINK_PREFIX.boost-build}/bin/bjam
BJAM_ARGS+=		--builddir=${WRKSRC}/build
BJAM_ARGS+=		--layout=system
BJAM_ARGS+=		--prefix=${PREFIX}
BJAM_ARGS+=		-sBUILD=${BJAM_BUILD:Q}
BJAM_ARGS+=		-sTOOLS=${BOOST_TOOLSET}
.if defined(BOOST_DEBUG) && !empty(BOOST_DEBUG:M[Yy][Ee][Ss])
BJAM_BUILD+=		debug
.endif
BJAM_BUILD+=		<linkflags>-Wl,-R${PREFIX}/lib
BJAM_BUILD+=		<threading>multi
BJAM_BUILD+=		release
BJAM_CMD=		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_ARGS}

bjam-build:
	@cd ${WRKSRC} && ${BJAM_CMD} stage

bjam-install:
	@cd ${WRKSRC} && ${BJAM_CMD} install
