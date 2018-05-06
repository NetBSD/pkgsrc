# $NetBSD: Makefile,v 1.50 2018/05/06 18:46:09 minskim Exp $

BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate

.include "../../meta-pkgs/boost/Makefile.common"
PKGREVISION=		4

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
