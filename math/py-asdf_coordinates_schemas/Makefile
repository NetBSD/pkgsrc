# $NetBSD: Makefile,v 1.4 2025/04/15 16:31:37 adam Exp $

DISTNAME=	asdf_coordinates_schemas-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asdf_coordinates_schemas/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asdf-coordinates-schemas.readthedocs.io/en/latest/
COMMENT=	ASDF schemas for validating coordinates tags
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-asdf>=2.12.1:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-asdf-standard>=1.1.0:../../math/py-asdf-standard

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
