# $NetBSD: Makefile,v 1.47 2018/04/30 00:21:13 ryoon Exp $

BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate

.include "../../meta-pkgs/boost/Makefile.common"
PKGREVISION=		1

BJAM_ARGS+=		--without-\*

NO_BUILD=		yes

.include "../../devel/boost-jam/bjam.mk"

do-install: bjam-install
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type f -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} \;
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type d -exec ${CHMOD} ${PKGDIRMODE} {} \;

PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
