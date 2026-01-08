# $NetBSD: Makefile,v 1.14 2026/01/08 15:10:53 adam Exp $

DISTNAME=	gwcs-0.26.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gwcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gwcs.readthedocs.io/en/latest/
COMMENT=	Generalized World Coordinate System
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-asdf>=3.3.0:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-asdf_astropy>=0.8.0:../../math/py-asdf_astropy
DEPENDS+=	${PYPKGPREFIX}-asdf_wcs_schemas>=0.4.0:../../math/py-asdf_wcs_schemas
DEPENDS+=	${PYPKGPREFIX}-astropy>=6.0:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.14.1:../../math/py-scipy
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-astropy>=0.11.0:../../devel/py-test-astropy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>0:../../devel/py-test-doctestplus

PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-astropy

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
