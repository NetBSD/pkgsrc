# $NetBSD: Makefile,v 1.1 2024/05/15 06:58:37 wiz Exp $

DISTNAME=	asdf_wcs_schemas-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf_wcs_schemas/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asdf-wcs-schemas.readthedocs.io/en/stable
COMMENT=	ASDF schemas for validating WCS tags
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-asdf>=2.8.0:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=3:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-asdf_astropy>=0:../../math/py-asdf_astropy
TEST_DEPENDS+=	${PYPKGPREFIX}-asdf-standard>=1.1.0:../../math/py-asdf-standard
TEST_DEPENDS+=	${PYPKGPREFIX}-asdf-transform-schemas>=0.5.0:../../math/py-asdf-transform-schemas
TEST_DEPENDS+=	${PYPKGPREFIX}-asdf_coordinates_schemas>=0.3.0:../../math/py-asdf_coordinates_schemas

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
