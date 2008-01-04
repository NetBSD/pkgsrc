# $NetBSD: bjam.mk,v 1.2 2008/01/04 19:58:40 jmmv Exp $
#

.include "../../devel/boost-jam/buildlink3.mk"

.include "../../devel/boost-build/toolset.mk"
.include "../../mk/bsd.prefs.mk"

BJAM=			${BUILDLINK_PREFIX.boost-jam}/bin/bjam

BJAM_ARGS+=		--builddir=${WRKSRC}/build
BJAM_ARGS+=		--layout=system
BJAM_ARGS+=		--prefix=${PREFIX}
BJAM_ARGS+=		--toolset=${BOOST_TOOLSET}
.if ${OPSYS} == "Darwin"
BJAM_ARGS+=		-sTARGET_LIBDIR=${PREFIX}/lib
.endif
BJAM_ARGS+=		${BJAM_BUILD}

BJAM_BUILD+=		debug
BJAM_BUILD+=		release
BJAM_BUILD+=		threading=multi
BJAM_BUILD+=		link=shared,static

BJAM_CMD=		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_ARGS}

PKG_OPTIONS_VAR=	PKG_OPTIONS.boost
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

PLIST_SRC+=		PLIST

UNLIMIT_RESOURCES+=	datasize

bjam-build:
	@${_ULIMIT_CMD}							\
	cd ${WRKSRC} && ${BJAM_CMD} stage

bjam-install:
	@${_ULIMIT_CMD}							\
	cd ${WRKSRC} && ${BJAM_CMD} install
