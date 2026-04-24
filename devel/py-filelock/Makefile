# $NetBSD: Makefile,v 1.45 2026/04/24 10:16:04 adam Exp $

DISTNAME=	filelock-3.29.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/filelock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/filelock
COMMENT=	Platform independent file lock
LICENSE=	unlicense

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.29:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=1.3:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.15.1:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.4:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=21.2:../../devel/py-virtualenv

USE_LANGUAGES=	# none

# as of 3.24.3
# 1 failed, 327 passed, 20 skipped, 6 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
