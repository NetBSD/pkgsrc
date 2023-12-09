# $NetBSD: Makefile,v 1.19 2023/12/09 12:31:14 kleink Exp $

DISTNAME=	geojson-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geojson/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/geojson
COMMENT=	Python bindings and utlities for GeoJSON
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
