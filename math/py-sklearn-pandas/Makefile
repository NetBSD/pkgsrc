# $NetBSD: Makefile,v 1.7 2023/08/01 23:20:49 wiz Exp $

DISTNAME=	sklearn-pandas-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sklearn-pandas/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/paulgb/sklearn-pandas
COMMENT=	Pandas integration with sklearn
LICENSE=	zlib AND 2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.17:../../math/py-scikit-learn

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
