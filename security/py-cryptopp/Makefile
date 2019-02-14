# $NetBSD: Makefile,v 1.18 2019/02/14 12:56:38 adam Exp $

VERSION=	0.7.1
VERSION_HASH=	869544967005693312591928092448767568728501330214
DISTNAME=	pycryptopp-${VERSION}.${VERSION_HASH}
PKGNAME=	${PYPKGPREFIX}-cryptopp-${VERSION}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycryptopp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tahoe-lafs.org/trac/pycryptopp
COMMENT=	Python wrapper for (and copy of parts of) crypto++
LICENSE=	gnu-gpl-v2 OR mit
# or Transitive Grace Period Public Licence, version 1.0 or later

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
