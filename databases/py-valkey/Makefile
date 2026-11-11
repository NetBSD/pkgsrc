# $NetBSD: Makefile,v 1.1 2026/11/11 22:43:03 wiz Exp $

DISTNAME=	valkey-6.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/valkey/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/valkey-io/valkey-py
COMMENT=	Python client for Valkey forked from redis-py
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-cachetools>=0:../../devel/py-cachetools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

# as of 6.2.0, complains about missing SSL certificates
# 3 warnings, 2 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
