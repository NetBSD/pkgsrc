# $NetBSD: Makefile,v 1.20 2026/10/20 06:13:09 adam Exp $

DISTNAME=	photutils-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/photutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://photutils.readthedocs.io/
COMMENT=	Astropy coordinated module for astronomical photometry
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.1.2:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-extension-helpers>=1.3:../../devel/py-extension-helpers
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-astropy>=7.0:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.15.0:../../math/py-scipy

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
