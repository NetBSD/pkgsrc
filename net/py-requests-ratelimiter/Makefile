# $NetBSD: Makefile,v 1.3 2026/04/05 11:45:47 wiz Exp $

DISTNAME=	requests_ratelimiter-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-ratelimiter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JWCook/requests-ratelimiter
COMMENT=	Rate-limiting for the requests library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-pyrate-limiter>=4.0:../../net/py-pyrate-limiter
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-cache>=1.2:../../devel/py-requests-cache
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=1.11:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
