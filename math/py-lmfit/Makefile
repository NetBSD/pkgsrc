# $NetBSD: Makefile,v 1.25 2025/07/03 19:18:08 wiz Exp $

DISTNAME=	lmfit-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lmfit/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://lmfit.github.io/lmfit-py/
COMMENT=	Least-squares minimization with bounds and constraints
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-asteval>=1.0:../../math/py-asteval
DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.4:../../textproc/py-dill
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.24:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.10.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-uncertainties>=3.2.2:../../math/py-uncertainties

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
