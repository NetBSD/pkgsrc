# $NetBSD: Makefile,v 1.1 2004/06/06 23:51:37 tv Exp $
#

BOOST_PKGNAME_ADD=	-thread
BJAM_ARGS+=		--without-python
BJAM_BUILD+=		<threading>multi

COMMENT=		Threading support for Boost C++ libraries

.include "../boost/Makefile.common"

do-configure: userhpp-configure
	${LN} -s -f user.hpp ${WRKSRC}/boost/config/thread_user.hpp

do-build:
	@cd ${WRKSRC} && ${BJAM_CMD} stage

do-install:
	${INSTALL_DATA} ${WRKSRC}/boost/config/user.hpp \
		${PREFIX}/include/boost-1_31/boost/config/thread_user.hpp
	${INSTALL_LIB} ${WRKSRC}/stage/lib/*-1_31.* ${PREFIX}/lib/
	@cd ${WRKSRC}/stage/lib && for f in *-1_31.*; do \
		${LN} -f ${PREFIX}/lib/$$f \
			${PREFIX}/lib/`${ECHO} $$f | ${SED} s,-1_31,,`; \
	done

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
