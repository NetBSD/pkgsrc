# $NetBSD: Makefile,v 1.3 2020/04/11 13:47:08 adam Exp $

DISTNAME=	xarray-0.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xarray/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pydata/xarray
COMMENT=	N-D labeled arrays and datasets in Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-setuptools>=41.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-pandads

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
