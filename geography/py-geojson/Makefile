# $NetBSD: Makefile,v 1.23 2025/10/09 11:15:34 wiz Exp $

DISTNAME=	geojson-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geojson/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/geojson
COMMENT=	Python bindings and utlities for GeoJSON
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 3.2.0: "Sorry, only Python 3.7 - 3.13 are supported at this time."
PYTHON_VERSIONS_INCOMPATIBLE=	314

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
