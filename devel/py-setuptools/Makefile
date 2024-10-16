# $NetBSD: Makefile,v 1.257 2024/10/16 17:52:05 adam Exp $

DISTNAME=	setuptools-75.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools
COMMENT=	New Python packaging system
LICENSE=	python-software-foundation OR zpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-build>=1.0.3:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock>=3.4.0:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-ini2toml>=0.14:../../textproc/py-ini2toml
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.develop>=7.21:../../devel/py-jaraco.develop
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.envs>=2.2:../../devel/py-jaraco.envs
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.path>=3.2.0:../../devel/py-jaraco.path
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.test-[0-9]*:../../devel/py-jaraco.test
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=23.2:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=19.1:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-test-checkdocs>=2.4:../../devel/py-test-checkdocs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-fixture-config-[0-9]*:../../devel/py-test-fixture-config
TEST_DEPENDS+=	${PYPKGPREFIX}-test-home>=0.5:../../devel/py-test-home
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subprocess-[0-9]*:../../devel/py-test-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli_w>=1.0.0:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=13.0.0:../../devel/py-virtualenv

# Pick setuptools.tests which are not built nor installed.
TEST_ENV+=	PYTHONPATH=${WRKSRC}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
