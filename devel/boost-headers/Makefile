# $NetBSD: Makefile,v 1.3 2005/02/27 21:57:53 jmmv Exp $
#

BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--with-unknown # disable all libraries

NO_BUILD=		# defined

.include "../../devel/boost-build/bjam.mk"

do-install: bjam-install
	${FIND} ${PREFIX}/include/boost \
		-type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${PREFIX}/include/boost \
		-type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}

PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
