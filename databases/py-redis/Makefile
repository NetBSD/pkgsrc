# $NetBSD: Makefile,v 1.46 2024/06/14 15:14:24 adam Exp $

DISTNAME=	redis-5.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/redis/redis-py
COMMENT=	Redis Python client
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.3:../../devel/py-async-timeout
.endif

# Testing requires a running redis-server.
# Broken in 4.1.0: missing SSL certificates and tox.ini.

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
