# $NetBSD: Makefile,v 1.12 2023/09/03 10:56:24 kleink Exp $

DISTNAME=	googlemaps-4.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/googlemaps/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/googlemaps/google-maps-services-python
COMMENT=	Python client library for Google Maps Platform
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
