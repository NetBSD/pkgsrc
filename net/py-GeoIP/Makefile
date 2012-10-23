# $NetBSD: Makefile,v 1.12 2012/10/23 17:19:01 asau Exp $
#

DISTNAME=	GeoIP-Python-1.2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python-//}
CATEGORIES=	net python
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/python/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.maxmind.com/app/python
COMMENT=	GeoIP support for Python
LICENSE=	gnu-lgpl-v2.1

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
