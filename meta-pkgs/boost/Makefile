# $NetBSD: Makefile,v 1.27 2023/01/22 16:24:29 ryoon Exp $

BOOST_PACKAGE=	meta-pkg
BOOST_COMMENT=	(meta package)

META_PACKAGE=	yes

.include "Makefile.common"

BOOST_DEPENDS_VERSION=	${BOOST_SHORT_VERSION:S/_/./}{,nb*,.*}

CATEGORIES+=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.boost.org/
COMMENT=	Free, peer-reviewed portable C++ source libraries

DEPENDS+=	boost-build-${BOOST_DEPENDS_VERSION}:../../devel/boost-build
DEPENDS+=	boost-docs-${BOOST_DEPENDS_VERSION}:../../devel/boost-docs
DEPENDS+=	boost-headers-${BOOST_DEPENDS_VERSION}:../../devel/boost-headers
DEPENDS+=	boost-jam-${BOOST_DEPENDS_VERSION}:../../devel/boost-jam
DEPENDS+=	boost-libs-${BOOST_DEPENDS_VERSION}:../../devel/boost-libs
DEPENDS+=	boost-mpi-${BOOST_DEPENDS_VERSION}:../../devel/boost-mpi
DEPENDS+=	${PYPKGPREFIX}-boost-${BOOST_DEPENDS_VERSION}:../../devel/py-boost

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
