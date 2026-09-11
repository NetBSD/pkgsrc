# $NetBSD: Makefile,v 1.12 2026/09/11 12:16:39 adam Exp $

DISTNAME=	matrix_nio-0.26.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	chat devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matrix-nio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matrix-nio/matrix-nio
COMMENT=	Matrix client library for Python
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiofiles>=24.1:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.10:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-socks>=0.8:../../www/py-aiohttp-socks
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.10:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-h11>=0.14:../../www/py-h11
DEPENDS+=	${PYPKGPREFIX}-h2>=4.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.14:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=2.1:../../devel/py-unpaddedbase64
# e2e
DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=1.4:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-cachetools>=5.3:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-peewee>=3.14:../../databases/py-peewee
DEPENDS+=	${PYPKGPREFIX}-vodozemac>=0.9.0:../../security/py-vodozemac

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-peewee -> py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
