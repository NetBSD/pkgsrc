# $NetBSD: Makefile,v 1.4 2005/08/12 20:58:45 jmmv Exp $
#

BOOST_PACKAGE=	meta-pkg
BOOST_COMMENT=	(meta package)

.include "Makefile.common"

CATEGORIES+=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.boost.org/
COMMENT=	Free, peer-reviewed portable C++ source libraries

DEPENDS+=	boost-build>=${BOOST_VERSION}:../../devel/boost-build
DEPENDS+=	boost-docs>=${BOOST_VERSION}:../../devel/boost-docs
DEPENDS+=	boost-headers>=${BOOST_VERSION}:../../devel/boost-headers
DEPENDS+=	boost-libs>=${BOOST_VERSION}:../../devel/boost-libs
DEPENDS+=	boost-python>=${BOOST_VERSION}:../../devel/boost-python

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-patch:	# empty

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
