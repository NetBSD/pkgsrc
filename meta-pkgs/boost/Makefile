# $NetBSD: Makefile,v 1.6 2006/05/17 16:22:46 tv Exp $
#

BOOST_PACKAGE=	meta-pkg
BOOST_COMMENT=	(meta package)
PKGREVISION=	2

.include "Makefile.common"

BOOST_DEPENDS_VERSION=	${BOOST_SHORT_VERSION:S/_/./}{,nb*,.*}

CATEGORIES+=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.boost.org/
COMMENT=	Free, peer-reviewed portable C++ source libraries

DEPENDS+=	boost-build-${BOOST_DEPENDS_VERSION}:../../devel/boost-build
DEPENDS+=	boost-docs-${BOOST_DEPENDS_VERSION}:../../devel/boost-docs
DEPENDS+=	boost-headers-${BOOST_DEPENDS_VERSION}:../../devel/boost-headers
DEPENDS+=	boost-libs-${BOOST_DEPENDS_VERSION}:../../devel/boost-libs
DEPENDS+=	boost-python-${BOOST_DEPENDS_VERSION}:../../devel/boost-python

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-patch:	# empty

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
