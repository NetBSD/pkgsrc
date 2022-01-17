# $NetBSD: Makefile,v 1.21 2022/01/17 19:02:13 adam Exp $

DISTNAME=	redis-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andymccurdy/redis-py
COMMENT=	Redis Python client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-deprecated>=1.2.3:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
# testing requires a running redis-server
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=1.0:../../devel/py-importlib-metadata
.endif

# Broken in 4.1.0: missing SSL certificates and tox.ini.
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
