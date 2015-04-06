# $NetBSD: Makefile,v 1.15 2015/04/06 08:17:32 adam Exp $

BOOST_PACKAGE=	meta-pkg
BOOST_COMMENT=	(meta package)

META_PACKAGE=	yes

PKGREVISION= 1
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
DEPENDS+=	boost-python-${BOOST_DEPENDS_VERSION}:../../devel/boost-python

.include "../../mk/bsd.pkg.mk"
