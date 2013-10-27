# $NetBSD: Makefile,v 1.27 2013/10/27 20:31:58 joerg Exp $

BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate
PKGREVISION=		2

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--without-* # disable all libraries

.include "../../devel/boost-jam/bjam.mk"

do-build:

do-install: bjam-install
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}

PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
