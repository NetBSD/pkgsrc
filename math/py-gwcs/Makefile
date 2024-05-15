# $NetBSD: Makefile,v 1.7 2024/05/15 07:01:41 wiz Exp $

DISTNAME=	gwcs-0.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gwcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gwcs.readthedocs.io/en/latest/
COMMENT=	Generalized World Coordinate System
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-asdf>=2.8.1:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-asdf_astropy>=0.2.0:../../math/py-asdf_astropy
DEPENDS+=	${PYPKGPREFIX}-asdf_wcs_schemas>=0.4.0:../../math/py-asdf_wcs_schemas
DEPENDS+=	${PYPKGPREFIX}-astropy>=5.3:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>=0:../../devel/py-test-doctestplus

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
