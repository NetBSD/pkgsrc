# $NetBSD: Makefile,v 1.236 2023/10/14 10:47:56 adam Exp $

DISTNAME=	setuptools-68.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools
COMMENT=	New Python packaging system
LICENSE=	python-software-foundation OR zpl-2.0

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
TEST_DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock>=3.4.0:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-ini2toml>=0.9:../../textproc/py-ini2toml
#TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.develop>=7.21:../../devel/py-jaraco.develop
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.envs>=2.2:../../devel/py-jaraco.envs
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.path>=3.2.0:../../devel/py-jaraco.path
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=19.1:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-pip-run>=8.8:../../devel/py-pip-run
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-checkdocs>=2.4:../../devel/py-test-checkdocs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-fixture-config-[0-9]*:../../devel/py-test-fixture-config
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli_w>=1.0.0:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=13.0.0:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

# 28 failed, 1104 passed, 27 skipped, 6 xfailed, 3 xpassed, 1 warning
PYSETUPTESTTARGET=	pytest

BOOTSTRAP_SETUPTOOLS=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
