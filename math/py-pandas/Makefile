# $NetBSD: Makefile,v 1.54 2023/10/29 17:39:51 adam Exp $

DISTNAME=	pandas-2.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://pandas.pydata.org/
COMMENT=	Python Data Analysis Library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.33:../../devel/py-cython
# Package directly expresses a meson minimum; we need higher to pick up our
# multi-version build fixes.
TOOL_DEPENDS+=	meson>=1.2.2nb1:../../devel/meson
TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.13.1:../../devel/py-meson_python
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer-[0-9]*:../../devel/py-versioneer
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz>=2020.1:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-tzdata>=2022.1:../../time/py-tzdata
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.34.2:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.3.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.17.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.2.0:../../devel/py-test-xdist

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

USE_CXX_FEATURES=	c++11

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing python binary name.
SUBST_FILES.python=	meson.build
SUBST_VARS.python=	TOOL_PYTHONBIN

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

# This would otherwise be installed, causing PLIST mismatch
post-patch:
	cd ${WRKSRC} && ${RM} -f pandas/_libs/window/aggregations.pyx.orig

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} pandas

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.py-numpy+= ${PYPKGPREFIX}-numpy>=1.23.2
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
