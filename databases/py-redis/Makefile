# $NetBSD: Makefile,v 1.30 2022/11/22 19:12:27 adam Exp $

DISTNAME=	redis-4.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/redis/redis-py
COMMENT=	Redis Python client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.2:../../devel/py-async-timeout
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
# testing requires a running redis-server
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Broken in 4.1.0: missing SSL certificates and tox.ini.
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
