# $NetBSD: Makefile,v 1.8 2007/06/02 17:51:48 jmmv Exp $
#

BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--with-unknown # disable all libraries

.include "../../devel/boost-jam/bjam.mk"

# The following is a quick hack to let boost compile under NetBSD with GCC 4.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && !empty(CC_VERSION:Mgcc-4.*)
post-configure:
	${ECHO} "#define BOOST_NO_STD_WSTREAMBUF" \
		>>${WRKSRC}/boost/config/user.hpp
.endif

do-build:

do-install: bjam-install
	${FIND} ${PREFIX}/include/boost \
		-type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${PREFIX}/include/boost \
		-type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}

PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
