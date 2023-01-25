# $NetBSD: Makefile,v 1.42 2023/01/25 14:05:16 adam Exp $

DISTNAME=	pandas-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://pandas.pydata.org/
COMMENT=	Python Data Analysis Library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-pytz>=2020.1:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.5.3:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.31:../../devel/py-test-xdist

USE_LANGUAGES=	c c++11

GCC_REQD=	8

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # py-scipy

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} pandas

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+= ${PYPKGPREFIX}-numpy>=1.23.2
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
