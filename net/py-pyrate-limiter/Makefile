# $NetBSD: Makefile,v 1.2 2026/03/29 18:30:19 wiz Exp $

DISTNAME=	pyrate_limiter-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyrate-limiter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vutran1710/PyrateLimiter
COMMENT=	Rate-Limiter using Leaky-Bucket Algorithm
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-dynamic-versioning>0:../../devel/py-uv-dynamic-versioning
# optional dependency
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock>=0:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=1.1.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6.2.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.16.0:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.8.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
