# $NetBSD: Makefile,v 1.10 2008/02/05 22:34:47 heinz Exp $
#

BOOST_PACKAGE=	meta-pkg
BOOST_COMMENT=	(meta package)
PKGREVISION=	3

PKG_DESTDIR_SUPPORT=	user-destdir

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
DEPENDS+=	boost-jam-${BOOST_DEPENDS_VERSION}:../../devel/boost-jam
DEPENDS+=	boost-libs-${BOOST_DEPENDS_VERSION}:../../devel/boost-libs
DEPENDS+=	boost-python-${BOOST_DEPENDS_VERSION}:../../devel/boost-python

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
