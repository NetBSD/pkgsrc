# $NetBSD: Makefile,v 1.29 2022/07/05 10:19:15 adam Exp $

DISTNAME=	redis-4.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/redis/redis-py
COMMENT=	Redis Python client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.2:../../devel/py-async-timeout
DEPENDS+=	${PYPKGPREFIX}-deprecated>=1.2.3:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
# testing requires a running redis-server
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=1.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>0:../../devel/py-typing-extensions
.endif

# Broken in 4.1.0: missing SSL certificates and tox.ini.
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
