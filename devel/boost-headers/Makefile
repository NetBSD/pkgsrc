# $NetBSD: Makefile,v 1.1 2005/02/26 22:48:35 jmmv Exp $
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

.include "../../mk/bsd.pkg.mk"
