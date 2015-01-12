# $NetBSD: Makefile,v 1.1 2015/01/12 10:27:41 kleink Exp $

DISTNAME=	google-maps-services-python-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	-https://github.com/googlemaps/google-maps-services-python/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/googlemaps/google-maps-services-python/
COMMENT=	Python client library for Google Maps API Web Services
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

EGG_NAME=	googlemaps
PYTHON_VERSIONS_INCOMPATIBLE=	33

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
