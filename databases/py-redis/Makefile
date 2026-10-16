# $NetBSD: Makefile,v 1.62 2026/10/16 17:54:22 adam Exp $

DISTNAME=	redis-8.1.0
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
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

# Testing requires a running redis-server.
# Broken in 4.1.0: missing SSL certificates and tox.ini.

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
