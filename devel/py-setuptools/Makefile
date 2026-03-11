# $NetBSD: Makefile,v 1.276 2026/03/11 10:08:03 adam Exp $

DISTNAME=	setuptools-82.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools
COMMENT=	New Python packaging system
LICENSE=	python-software-foundation OR zpl-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-build>=1.0.3:../../devel/py-build
# not listed in pyproject but needed
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock>=3.4.0:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-ini2toml>=0.14:../../textproc/py-ini2toml
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.develop>=7.21:../../devel/py-jaraco.develop
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.envs>=2.2:../../devel/py-jaraco.envs
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.path>=3.7.2:../../devel/py-jaraco.path
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.test>=5.5:../../devel/py-jaraco.test
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=24.2:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=19.1:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-test-home>=0.5:../../devel/py-test-home
# listed in pyprojects, but makes more tests fail
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-perf>=0:../../devel/py-test-perf
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subprocess-[0-9]*:../../devel/py-test-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli_w>=1.0.0:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=13.0.0:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.44.0:../../devel/py-wheel
# pyproject-hooks

REPLACE_PYTHON+=	setuptools/_vendor/bin/wheel

# Pick setuptools.tests which are not built nor installed.
TEST_ENV+=	PYTHONPATH=${WRKSRC}

# as of 82.0.0
# 9 failed, 989 passed, 31 skipped, 14 xfailed, 3 xpassed
.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
