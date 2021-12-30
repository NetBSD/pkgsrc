# $NetBSD: Makefile,v 1.36 2021/12/30 13:05:37 adam Exp $

DISTNAME=	pandas-1.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://pandas.pydata.org/
COMMENT=	Python Data Analysis Library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-bottleneck-[0-9]*:../../math/py-bottleneck
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7.3:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numexpr-[0-9]*:../../math/py-numexpr
DEPENDS+=	${PYPKGPREFIX}-pytz>=2017.3:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-tables>=2.2:../../math/py-tables
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=3.58:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.0.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	c c++

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.pynumpy+= ${PYPKGPREFIX}-numpy>=1.16.5
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
