# $NetBSD: Makefile,v 1.4 2024/02/11 19:46:01 adam Exp $

DISTNAME=	matrix_nio-0.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	chat devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matrix-nio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/poljar/matrix-nio
COMMENT=	Matrix client library for Python
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-aiofiles>=23.1.0:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.9.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-socks>=0.8.4:../../www/py-aiohttp-socks
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.10.1:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-h11>=0.14.0:../../www/py-h11
DEPENDS+=	${PYPKGPREFIX}-h2>=4.0.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.14.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=2.1.0:../../devel/py-unpaddedbase64
# optional
DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=1.4.0:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-cachetools>=4.2.1:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-olm>=3.2.2:../../security/py-olm
DEPENDS+=	${PYPKGPREFIX}-peewee>=3.14.4:../../databases/py-peewee

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
