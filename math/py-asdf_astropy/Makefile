# $NetBSD: Makefile,v 1.5 2025/01/21 09:35:01 adam Exp $

DISTNAME=	asdf_astropy-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf_astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asdf-astropy.readthedocs.io/en/latest/
COMMENT=	ASDF serialization support for astropy objects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-asdf>=2.14.4:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-asdf_coordinates_schemas>=0.3:../../math/py-asdf_coordinates_schemas
DEPENDS+=	${PYPKGPREFIX}-asdf-standard>=1.1.0:../../math/py-asdf-standard
DEPENDS+=	${PYPKGPREFIX}-asdf-transform-schemas>=0.5:../../math/py-asdf-transform-schemas
DEPENDS+=	${PYPKGPREFIX}-astropy>=5.2.0:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.24:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging>=19:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>=0:../../devel/py-test-doctestplus
TEST_DEPENDS+=	${PYPKGPREFIX}-scipy>0:../../math/py-scipy
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-astropy>0:../../math/py-test-astropy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
