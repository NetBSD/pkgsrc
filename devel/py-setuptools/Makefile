# $NetBSD: Makefile,v 1.245 2024/06/08 12:40:24 wiz Exp $

DISTNAME=	setuptools-70.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools
COMMENT=	New Python packaging system
LICENSE=	python-software-foundation OR zpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock>=3.4.0:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-ini2toml>=0.9:../../textproc/py-ini2toml
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.develop>=7.21:../../devel/py-jaraco.develop
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.envs>=2.2:../../devel/py-jaraco.envs
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.path>=3.2.0:../../devel/py-jaraco.path
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=19.1:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-test-checkdocs>=2.4:../../devel/py-test-checkdocs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-fixture-config-[0-9]*:../../devel/py-test-fixture-config
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli_w>=1.0.0:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=13.0.0:../../devel/py-virtualenv

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Pick setuptools.tests which are not built nor installed.
# 29 failed, 1076 passed, 35 skipped, 9 xfailed, 2 xpassed, 54 errors
TEST_ENV+=	PYTHONPATH=${WRKSRC}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
