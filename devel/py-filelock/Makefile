# $NetBSD: Makefile,v 1.48 2026/06/22 19:59:25 wiz Exp $

DISTNAME=	filelock-3.29.4
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

# as of 3.29.4
# 6 failed, 463 passed, 25 skipped, 6 warnings, 1 error
# https://github.com/tox-dev/filelock/issues/569

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
