# $NetBSD: Makefile,v 1.52 2025/05/28 14:16:23 adam Exp $

DISTNAME=	redis-6.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/redis/redis-py
COMMENT=	Redis Python client
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.3:../../devel/py-async-timeout
.endif

# Testing requires a running redis-server.
# Broken in 4.1.0: missing SSL certificates and tox.ini.

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
