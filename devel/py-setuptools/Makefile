# $NetBSD: Makefile,v 1.237 2023/10/23 06:39:18 wiz Exp $

DISTNAME=	setuptools-68.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools
COMMENT=	New Python packaging system
LICENSE=	python-software-foundation OR zpl-2.0

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

PYDISTUTILSPKG=		no
PY_PATCHPLIST=		yes
#BOOTSTRAP_SETUPTOOLS=	yes

do-build: ensurepip
.PHONY: ensurepip

ensurepip:
	${SETENV} ${MAKE_ENV} ${TOOL_PYTHONBIN} -m ensurepip --user

do-install:
	cd ${WRKSRC} && PYTHONPATH=${WRKDIR}/.home/.local/lib/python${PYVERSSUFFIX}/site-packages \
        ${TOOL_PYTHONBIN} -m pip install --no-cache-dir --no-deps --disable-pip-version-check \
                --root ${DESTDIR:Q} --prefix ${PREFIX:Q} --compile --force-reinstall -I .

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
