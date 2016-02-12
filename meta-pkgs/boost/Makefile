# $NetBSD: Makefile,v 1.20 2016/02/12 14:24:50 ryoon Exp $

PKGREVISION=	1
BOOST_PACKAGE=	meta-pkg
BOOST_COMMENT=	(meta package)

META_PACKAGE=	yes

.include "Makefile.common"

BOOST_DEPENDS_VERSION=	${BOOST_SHORT_VERSION:S/_/./}{,nb*,.*}

CATEGORIES+=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.boost.org/
COMMENT=	Free, peer-reviewed portable C++ source libraries

DEPENDS+=	boost-build-${BOOST_DEPENDS_VERSION}:../../devel/boost-build
DEPENDS+=	boost-docs-${BOOST_DEPENDS_VERSION}:../../devel/boost-docs
DEPENDS+=	boost-headers-${BOOST_DEPENDS_VERSION}:../../devel/boost-headers
DEPENDS+=	boost-jam-${BOOST_DEPENDS_VERSION}:../../devel/boost-jam
DEPENDS+=	boost-libs-${BOOST_DEPENDS_VERSION}:../../devel/boost-libs
DEPENDS+=	${PYPKGPREFIX}-boost-${BOOST_DEPENDS_VERSION}:../../devel/py-boost

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
