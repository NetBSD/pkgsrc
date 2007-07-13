# $NetBSD: Makefile,v 1.6 2007/07/13 07:31:54 obache Exp $
#

DISTNAME=	GeoIP-Python-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Python-//}
CATEGORIES=	net python
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/python/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://www.maxmind.com/app/python
COMMENT=	GeoIP support for Python

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
