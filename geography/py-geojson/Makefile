# $NetBSD: Makefile,v 1.18 2023/11/05 11:49:10 wiz Exp $

DISTNAME=	geojson-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geojson/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/geojson
COMMENT=	Python bindings and utlities for GeoJSON
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27 312

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
