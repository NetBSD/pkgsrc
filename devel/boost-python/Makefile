# $NetBSD: Makefile,v 1.2 2004/06/07 01:34:25 tv Exp $
#

BOOST_PKGNAME_ADD=	-python
BJAM_ARGS+=		--without-date_time
BJAM_ARGS+=		--without-filesystem
BJAM_ARGS+=		--without-regex
BJAM_ARGS+=		--without-signals
BJAM_ARGS+=		--without-test
BJAM_ARGS+=		--without-thread
BJAM_ARGS+=		-sPYTHON_ROOT=${PREFIX}
BJAM_ARGS+=		-sPYTHON_VERSION=${PYVERSSUFFIX}

# this pkg doesn't support threaded python yet:
BJAM_BUILD+=		<threading>single
PYTHON_VERSIONS_INCOMPATIBLE+= 23pth 22pth 21 21pth 20 15

COMMENT=		Python support for Boost C++ libraries

.include "../boost/Makefile.common"

do-configure:
	${CP} -f ${LOCALBASE}/include/boost-1_31/boost/config/user.hpp \
		${WRKSRC}/boost/config/user.hpp

do-build:
	@cd ${WRKSRC} && ${BJAM_CMD} stage

do-install:
	${INSTALL_LIB} ${WRKSRC}/stage/lib/*-1_31.* ${PREFIX}/lib/
	@cd ${WRKSRC}/stage/lib && for f in *-1_31.*; do \
		${LN} -f ${PREFIX}/lib/$$f \
			${PREFIX}/lib/`${ECHO} $$f | ${SED} s,-1_31,,`; \
	done

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
