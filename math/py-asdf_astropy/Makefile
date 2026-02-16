# $NetBSD: Makefile,v 1.11 2026/02/16 09:43:06 adam Exp $

DISTNAME=	asdf_astropy-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf_astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asdf-astropy.readthedocs.io/en/latest/
COMMENT=	ASDF serialization support for astropy objects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-asdf>=3.3.0:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-asdf_coordinates_schemas>=0.4:../../math/py-asdf_coordinates_schemas
DEPENDS+=	${PYPKGPREFIX}-asdf-standard>=1.1.0:../../math/py-asdf-standard
DEPENDS+=	${PYPKGPREFIX}-asdf-transform-schemas>=0.6:../../math/py-asdf-transform-schemas
DEPENDS+=	${PYPKGPREFIX}-astropy>=5.3.0:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.26.4:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging>=19:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>=0:../../devel/py-test-doctestplus
TEST_DEPENDS+=	${PYPKGPREFIX}-scipy>0:../../math/py-scipy
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-astropy>0:../../math/py-test-astropy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
