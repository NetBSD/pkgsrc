# $NetBSD: Makefile,v 1.7 2024/06/10 09:47:55 adam Exp $

DISTNAME=	scikit_build_core-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-build-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scikit-build/scikit-build-core
COMMENT=	Build backend for CMake based projects
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.10.1:../../devel/py-pathspec
TEST_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TEST_DEPENDS+=	${PYPKGPREFIX}-build>=0.8:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-cattrs>=22.2.0:../../devel/py-cattrs
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=22:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-pybind11>=2.11:../../devel/py-pybind11
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=66.1:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subprocess>=1.5:../../devel/py-test-subprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.0.28:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.40:../../devel/py-wheel

# only needed for tests
USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.3:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.0:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.2.2:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
# only needed for testing, but this is not supported by buildlink3, so make it build dependency
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
