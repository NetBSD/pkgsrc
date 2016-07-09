# $NetBSD: Makefile,v 1.7 2016/07/09 13:03:49 wiz Exp $

DISTNAME=	google-maps-services-python-2.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	-https://github.com/googlemaps/google-maps-services-python/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/googlemaps/google-maps-services-python/
COMMENT=	Python client library for Google Maps API Web Services
LICENSE=	apache-2.0

#DEPENDS+=	${PYPKGPREFIX}-requests<=2.9.1:../../devel/py-requests
BROKEN=		Needs old version of py-requests.

EGG_NAME=	googlemaps-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
