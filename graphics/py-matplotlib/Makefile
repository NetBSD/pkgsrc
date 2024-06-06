# $NetBSD: Makefile,v 1.95 2024/06/06 19:11:59 wiz Exp $

DISTNAME=	matplotlib-3.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matplotlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://matplotlib.org/
COMMENT=	Matlab-style plotting package for Python
# LICENSE=	see ${WRKSRC}/LICENSE/LICENSE

TOOL_DEPENDS+=	${PYPKGPREFIX}-certifi>=2020.06.20:../../security/py-certifi
TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0:../../devel/py-meson_python
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.0:../../graphics/py-Pillow
#DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-contourpy>=1.0.1:../../graphics/py-contourpy
DEPENDS+=	${PYPKGPREFIX}-cycler>=0.10:../../graphics/py-cycler
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-fonttools>=4.22.0:../../fonts/py-fonttools
DEPENDS+=	${PYPKGPREFIX}-kiwisolver>=1.3.1:../../math/py-kiwisolver
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.3.1:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

WHEEL_ARGS+=	-Csetup-args="-Dsystem-freetype=true"
WHEEL_ARGS+=	-Csetup-args="-Dsystem-qhull=true"
WHEEL_ARGS+=	-Csetup-args="-Db_lto=false"
# install test data, per
# https://matplotlib.org/stable/api/prev_api_changes/api_changes_3.9.0.html#build-system-ported-to-meson
# so that test target can work
WHEEL_ARGS+=	-Cinstall-args="--tags=data,python-runtime,runtime,tests"

# py-pybind11's bl3 defaults to PYTHON_FOR_BUILD_ONLY?=yes as it is primarily
# used by packages that only have a build dependency on it.  Therefore we need
# to ensure that we set it to "no" first to get accurate dependencies.
PYTHON_FOR_BUILD_ONLY=	no
.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=3.2.0:../../devel/py-importlib-resources
.endif

# depends on do-install
# as of 3.9.0
# 928 failed, 6776 passed, 1785 skipped, 33 xfailed
# possible additional test dependencies to pass more tests include
# pikepdf, tex, qt, ghostscript, ...
# py-test command line comes from https://github.com/matplotlib/matplotlib/issues/28260
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} -ra -m 'not network' --pyargs matplotlib

.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
