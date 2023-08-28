# $NetBSD: Makefile,v 1.47 2023/08/28 10:34:02 adam Exp $

DISTNAME=	pandas-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://pandas.pydata.org/
COMMENT=	Python Data Analysis Library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.33:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer-[0-9]*:../../devel/py-versioneer
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz>=2020.1:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-tzdata>=2022.1:../../time/py-tzdata
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.34.2:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.3.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.17.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.2.0:../../devel/py-test-xdist

USE_LANGUAGES=	c c++11

GCC_REQD+=	8

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} pandas

# This would otherwise be installed, causing PLIST mismatch
post-patch:
	cd ${WRKSRC} && ${RM} -f pandas/_libs/window/aggregations.pyx.orig

.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.py-numpy+= ${PYPKGPREFIX}-numpy>=1.23.2
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
