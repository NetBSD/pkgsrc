# $NetBSD: Makefile,v 1.1 2024/05/15 06:46:57 wiz Exp $

DISTNAME=	asdf-astropy-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-/_/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf_astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asdf-astropy.readthedocs.io/en/latest/
COMMENT=	ASDF serialization support for astropy objects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-asdf>=2.13:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-asdf-standard>=1.1.0:../../math/py-asdf-standard
DEPENDS+=	${PYPKGPREFIX}-asdf-transform-schemas>=0.5:../../math/py-asdf-transform-schemas
DEPENDS+=	${PYPKGPREFIX}-asdf_coordinates_schemas>=0.3:../../math/py-asdf_coordinates_schemas
DEPENDS+=	${PYPKGPREFIX}-astropy>=5.0.4:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-numpy>0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging>=19:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>=0:../../devel/py-test-doctestplus
TEST_DEPENDS+=	${PYPKGPREFIX}-test-astropy-header>=0:../../devel/py-test-astropy-header

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
