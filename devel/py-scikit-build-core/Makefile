# $NetBSD: Makefile,v 1.1 2024/02/15 07:36:36 wiz Exp $

DISTNAME=	scikit_build_core-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-build-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scikit-build/scikit-build-core
COMMENT=	Build backend for CMake based projects
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
# optional
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.10.1:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-project-metadata>=0.5:../../devel/py-project-metadata
TEST_DEPENDS+=	${PYPKGPREFIX}-cattrs-[0-9]*:../../devel/py-cattrs
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-subprocess>=1.5:../../devel/py-test-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-pybind11-[0-9]*:../../devel/py-pybind11
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

# only needed for tests
USE_LANGUAGES=	c c++

# test status as of 0.8.1
# 183 passed, 54 skipped, 3 xfailed, 42 errors

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.3:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=1.3:../../devel/py-typing-extensions
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup-[0-9]*:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
# only needed for testing, but this is not supported by buildlink3, so make it build dependency
BUILDLINK_DEPMETHOD.py-pybind11=   build
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
