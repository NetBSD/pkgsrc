# $NetBSD: Makefile,v 1.9 2009/10/18 19:54:52 zafer Exp $
#

DISTNAME=	GeoIP-Python-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python-//}
CATEGORIES=	net python
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/python/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.maxmind.com/app/python
COMMENT=	GeoIP support for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
