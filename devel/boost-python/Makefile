# $NetBSD: Makefile,v 1.3 2005/02/26 22:48:35 jmmv Exp $
#

BOOST_PACKAGE=		python
BOOST_COMMENT=		(Boost.Python binary library)
BOOST_CONFIG=		installed

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--with-python
BJAM_ARGS+=		-sPYTHON_ROOT=${PREFIX}
BJAM_ARGS+=		-sPYTHON_VERSION=${PYVERSSUFFIX}

.include "../../devel/boost-build/bjam.mk"
.include "../../lang/python/application.mk"

do-build: bjam-build

do-install: boost-install-libs

.include "../../mk/bsd.pkg.mk"
