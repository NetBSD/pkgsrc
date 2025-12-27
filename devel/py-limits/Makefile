# $NetBSD: Makefile,v 1.26 2025/12/27 14:32:48 adam Exp $

DISTNAME=	limits-5.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/limits/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://limits.readthedocs.io/
COMMENT=	Rate limiting utilities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4.0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.14.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-deprecated>=1.2:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-packaging>=21:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-lazy-fixtures-[0-9]*:../../devel/py-test-lazy-fixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

# missing:
# - tests/__init__.py
# - tests/utils.py (https://raw.githubusercontent.com/alisaifee/limits/refs/heads/master/tests/utils.py)
pre-test:
	${RM} -f ${WRKSRC}/tests/test_storage.py ${WRKSRC}/tests/test_strategy.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
