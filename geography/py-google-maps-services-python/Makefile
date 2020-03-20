# $NetBSD: Makefile,v 1.11 2020/03/20 07:28:14 wiz Exp $

DISTNAME=	google-maps-services-python-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	-https://github.com/googlemaps/google-maps-services-python/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/googlemaps/google-maps-services-python/
COMMENT=	Python client library for Google Maps API Web Services
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0<3.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	googlemaps-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
