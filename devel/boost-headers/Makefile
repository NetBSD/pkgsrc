# $NetBSD: Makefile,v 1.32 2015/01/15 13:01:44 joerg Exp $

BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate
PKGREVISION=		1

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--without-* # disable all libraries

NO_BUILD=		yes

.include "../../devel/boost-jam/bjam.mk"

do-install: bjam-install
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}

PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
