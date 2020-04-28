# $NetBSD: Makefile,v 1.9 2020/04/28 13:27:03 adam Exp $

DISTNAME=	lmfit-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lmfit/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://lmfit.github.io/lmfit-py/
COMMENT=	Least-squares minimization with bounds and constraints
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-asteval>=0.9.16:../../math/py-asteval
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.16:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-uncertainties>=3.0.1:../../math/py-uncertainties

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
