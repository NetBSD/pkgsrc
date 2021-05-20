# $NetBSD: Makefile,v 1.8 2021/05/20 12:58:13 adam Exp $

DISTNAME=	xarray-0.18.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xarray/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pydata/xarray
COMMENT=	N-D labeled arrays and datasets in Python
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.4:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27 36	# py-pandas

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
