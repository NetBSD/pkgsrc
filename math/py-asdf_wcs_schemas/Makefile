# $NetBSD: Makefile,v 1.9 2026/01/23 05:49:55 wiz Exp $

DISTNAME=	asdf_wcs_schemas-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf_wcs_schemas/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asdf-format/asdf-wcs-schemas
COMMENT=	ASDF schemas for validating WCS tags
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-asdf-standard>=1.1.0:../../math/py-asdf-standard
DEPENDS+=	${PYPKGPREFIX}-asdf-transform-schemas>=0.6.0:../../math/py-asdf-transform-schemas
DEPENDS+=	${PYPKGPREFIX}-asdf_coordinates_schemas>=0.4.0:../../math/py-asdf_coordinates_schemas
TEST_DEPENDS+=	${PYPKGPREFIX}-asdf>=2.8.0:../../math/py-asdf
TEST_DEPENDS+=	${PYPKGPREFIX}-asdf_astropy>=0:../../math/py-asdf_astropy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-asdf_astropy

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
