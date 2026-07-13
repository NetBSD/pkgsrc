# $NetBSD: Makefile,v 1.25 2026/07/13 13:39:10 wiz Exp $

DISTNAME=	scikit_build_core-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-build-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scikit-build/scikit-build-core
COMMENT=	Build backend for CMake based projects
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.24:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.10.1:../../devel/py-pathspec
TEST_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TEST_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build
TEST_DEPENDS+=	${PYPKGPREFIX}-build>=0.8:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-cattrs>=22.2.0:../../devel/py-cattrs
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=24.1:../../devel/py-pip
# pybind11 uses this for building itself, so we can't depend on it
#TEST_DEPENDS+=	${PYPKGPREFIX}-pybind11>=2.11:../../devel/py-pybind11
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=66.1:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subprocess>=1.5:../../devel/py-test-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.1:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.20:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.40:../../devel/py-wheel

# only needed for tests
USE_LANGUAGES=	c c++

# as of 1.0.3
# 15 failed, 941 passed, 80 skipped
# with pybind11 from below:
# 19 failed, 943 passed, 74 skipped
.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

PY_RENAME_BINARIES+=	scikit-build
PY_RENAME_BINARIES+=	scikit-build-core

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.0:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.2.2:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
# only needed for testing, but this is not supported by buildlink3, so make it build dependency
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
