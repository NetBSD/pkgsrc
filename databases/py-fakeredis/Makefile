# $NetBSD: Makefile,v 1.1 2026/11/11 22:43:34 wiz Exp $

DISTNAME=	fakeredis-2.40.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fakeredis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cunla/fakeredis-py
COMMENT=	Python implementation of redis API, can be used for testing purposes
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=0:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-redis>=0:../../databases/py-redis
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-valkey>=0:../../databases/py-valkey
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
