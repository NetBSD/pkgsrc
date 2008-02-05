# $NetBSD: Makefile,v 1.10 2008/02/05 23:00:27 heinz Exp $
#

BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate

PKG_DESTDIR_SUPPORT=	user-destdir

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
