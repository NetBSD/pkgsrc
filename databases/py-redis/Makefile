# $NetBSD: Makefile,v 1.32 2023/01/09 11:27:02 adam Exp $

DISTNAME=	redis-4.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/redis/redis-py
COMMENT=	Redis Python client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.2:../../devel/py-async-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Testing requires a running redis-server.
# Broken in 4.1.0: missing SSL certificates and tox.ini.
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
