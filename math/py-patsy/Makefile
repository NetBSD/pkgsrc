# $NetBSD: Makefile,v 1.18 2025/01/14 16:50:57 adam Exp $

DISTNAME=	patsy-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/patsy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pydata/patsy
COMMENT=	Python package for describing statistical models
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

USE_LANGUAGES=	# none

# as of 0.5.6
# 6 failed, 142 passed

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
