# $NetBSD: Makefile,v 1.11 2014/05/09 07:37:18 wiz Exp $

VERSION=	0.6.0
VERSION_EXCESSIVE=	1206569328141510525648634803928199668821045408958
DISTNAME=	pycryptopp-${VERSION}.${VERSION_EXCESSIVE}
PKGNAME=	${PYPKGPREFIX}-cryptopp-${VERSION}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pycryptopp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/trac/pycryptopp
COMMENT=	Python wrapper for (and copy of parts of) crypto++
# GPL v2 or later.
# or Transitive Grace Period Public Licence, version 1.0 or later.
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

REPLACE_PYTHON=		pycryptopp/test/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.6.0.120...

# It would be nice if egg.mk had support for this.
#TEST_TARGET=	@python@ setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
