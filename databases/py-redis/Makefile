# $NetBSD: Makefile,v 1.43 2024/03/11 06:48:51 adam Exp $

DISTNAME=	redis-5.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/redis/redis-py
COMMENT=	Redis Python client
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.3:../../devel/py-async-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Testing requires a running redis-server.
# Broken in 4.1.0: missing SSL certificates and tox.ini.

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
