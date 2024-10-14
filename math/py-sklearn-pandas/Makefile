# $NetBSD: Makefile,v 1.9 2024/10/14 06:45:52 wiz Exp $

DISTNAME=	sklearn-pandas-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sklearn-pandas/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/paulgb/sklearn-pandas
COMMENT=	Pandas integration with sklearn
LICENSE=	zlib AND 2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.18.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.1.4:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.23.0:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.1:../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
