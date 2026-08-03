# $NetBSD: Makefile,v 1.71 2026/08/03 09:57:15 adam Exp $

DISTNAME=	pandas-3.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://pandas.pydata.org/
COMMENT=	Python Data Analysis Library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.1.0:../../devel/py-cython
# Package directly expresses a meson minimum; we need higher to pick up our
# multi-version build fixes.
TOOL_DEPENDS+=	meson>=1.2.2nb1:../../devel/meson
TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.17.1:../../devel/py-meson_python
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer-[0-9]*:../../devel/py-versioneer
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-tzdata>=2022.1:../../time/py-tzdata
# timezone
DEPENDS+=	${PYPKGPREFIX}-pytz>=2020.1:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.116.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

# __has_builtin
GCC_REQD+=		10

REPLACE_PYTHON+=	generate_version.py

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

# This would otherwise be installed, causing PLIST mismatch
post-patch:
	cd ${WRKSRC} && ${RM} -f pandas/_libs/window/aggregations.pyx.orig

.include "../../lang/python/application.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.py-numpy+= ${PYPKGPREFIX}-numpy>=2.3.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
