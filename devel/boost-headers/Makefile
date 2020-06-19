# $NetBSD: Makefile,v 1.59 2020/06/19 13:02:38 ryoon Exp $

PKGREVISION=		1
BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--without-\*

NO_BUILD=		yes

INSTALLATION_DIRS+=	include/boost

.include "../../devel/boost-jam/bjam.mk"

do-install: bjam-build
	${FIND} ${WRKSRC}/boost -type f -name '*.orig' | ${XARGS} ${RM} -f
	cd ${WRKSRC}/boost; ${FIND} . -type f -print | \
		pax -rw ${DESTDIR}${PREFIX}/include/boost
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type f -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} +
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type d -exec ${CHMOD} ${PKGDIRMODE} {} +

PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
