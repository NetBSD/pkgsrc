# $NetBSD: Makefile,v 1.2 2021/04/09 15:42:35 tnn Exp $

DISTNAME=	sklearn-pandas-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sklearn-pandas/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/paulgb/sklearn-pandas
COMMENT=	Pandas integration with sklearn
LICENSE=	zlib AND 2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.17:../../math/py-scikit-learn

PYTHON_VERSIONS_INCOMPATIBLE=	36 27	# py-scikit-learn

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
