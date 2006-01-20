# $NetBSD: Makefile,v 1.3 2006/01/20 20:40:19 jmmv Exp $
#

BOOST_PACKAGE=		build
BOOST_COMMENT=		(Boost.Build framework)
BOOST_CONFIG=		no

.include "../../meta-pkgs/boost/Makefile.common"

.include "toolset.mk"

INSTALLATION_DIRS=	bin

do-build:
	@cd ${WRKSRC}/tools/build/jam_src && \
	    ${SETENV} ${MAKE_ENV} ${SH} ./build.sh ${BOOST_TOOLSET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/build/jam_src/bin.*/bjam \
	    ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
