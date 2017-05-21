# $NetBSD: Makefile,v 1.15 2017/05/21 08:54:33 adam Exp $

DISTNAME=	pandas-0.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pandas/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://pandas.pydata.org/
COMMENT=	Python Data Analysis Library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-numexpr-[0-9]*:../../math/py-numexpr
DEPENDS+=	${PYPKGPREFIX}-pytz>=1.5:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pytables>=2.2:../../math/py-pytables
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
BUILDLINK_API_DEPENDS.pynumpy+= ${PYPKGPREFIX}-numpy>=1.7.0
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
# 20 test failures as of 0.18.1, see
# https://github.com/pydata/pandas/issues/12337
# https://github.com/pydata/pandas/issues/14043

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
USE_LANGUAGES=	c c++

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

# XXX want py-bottleneck
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
