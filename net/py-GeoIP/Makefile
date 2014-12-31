# $NetBSD: Makefile,v 1.15 2014/12/31 13:57:28 wiz Exp $

DISTNAME=	GeoIP-Python-1.2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python-//}
CATEGORIES=	net python geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/python/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.maxmind.com/app/python
COMMENT=	GeoIP support for Python
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.2.7

.include "../../lang/python/distutils.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
