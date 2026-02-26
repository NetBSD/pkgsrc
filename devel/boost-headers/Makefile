# $NetBSD: Makefile,v 1.75 2026/02/26 10:11:39 wiz Exp $

BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate

PKGREVISION=		2

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--with-headers

INSTALLATION_DIRS+=	include/boost lib/cmake

CONFLICTS+=	boost-libs<=1.90.0nb2

.include "../../devel/boost-jam/bjam.mk"

do-build: bjam-build

do-install: boost-install-cmake
do-install:
	@${STEP_MSG} Installing boost header files
	${FIND} ${WRKSRC}/boost -type f -name '*.orig' | ${XARGS} ${RM} -f
	cd ${WRKSRC}/boost; ${FIND} . -type f -print | \
		pax -rw ${DESTDIR}${PREFIX}/include/boost
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type f -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} +
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type d -exec ${CHMOD} ${PKGDIRMODE} {} +

# These are required only for boost-libs
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/Boost-*/*.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/BoostDetectToolset-*.cmake

PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
