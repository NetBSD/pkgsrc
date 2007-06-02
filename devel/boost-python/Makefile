# $NetBSD: Makefile,v 1.7 2007/06/02 17:51:49 jmmv Exp $
#

BOOST_PACKAGE=		python
BOOST_COMMENT=		(Boost.Python binary library)
BOOST_CONFIG=		installed
PKGREVISION=		1

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--with-python
BJAM_ARGS+=		-sPYTHON_ROOT=${PREFIX}
BJAM_ARGS+=		-sPYTHON_VERSION=${PYVERSSUFFIX}

.include "../../devel/boost-jam/bjam.mk"
.include "../../lang/python/application.mk"

do-build: bjam-build

do-install: boost-install-libs

.include "../../mk/bsd.pkg.mk"
