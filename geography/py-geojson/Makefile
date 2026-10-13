# $NetBSD: Makefile,v 1.25 2026/10/13 09:38:25 wiz Exp $

DISTNAME=	geojson-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geojson/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/geojson
COMMENT=	Python bindings and utlities for GeoJSON
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	315

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
