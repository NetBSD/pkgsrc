# $NetBSD: Makefile,v 1.19 2016/10/19 14:28:45 fhajny Exp $

DISTNAME=	geoip-api-python-1.3.2
PKGNAME=	${PYPKGPREFIX}-GeoIP-${DISTNAME:S/geoip-api-python-//}
CATEGORIES=	net python geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/maxmind/geoip-api-python/
COMMENT=	GeoIP Legacy Python API
LICENSE=	gnu-lgpl-v2.1

GITHUB_PROJECT=	geoip-api-python
GITHUB_TAG=	v${PKGVERSION_NOREV}

EGG_NAME=	GeoIP-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
