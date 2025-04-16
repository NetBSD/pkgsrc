# $NetBSD: Makefile,v 1.22 2025/04/16 14:38:57 adam Exp $

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

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
