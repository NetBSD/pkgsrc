# $NetBSD: Makefile,v 1.7 2019/06/15 07:21:21 adam Exp $

DISTNAME=	lmfit-0.9.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lmfit/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://lmfit.github.io/lmfit-py/
COMMENT=	Least-squares minimization with bounds and constraints
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-asteval>=0.9.12:../../math/py-asteval
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.10:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.19:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-uncertainties>=3.0:../../math/py-uncertainties

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
