# $NetBSD: Makefile,v 1.1.1.1 2004/03/07 18:45:42 minskim Exp $
#

DISTNAME=	GeoIP-Python-1.2.0
PKGNAME=	${PYPKGPREFIX}-GeoIP-1.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/python/

MAINTAINER=	bartosz@atom.eu.org
HOMEPAGE=	http://www.maxmind.com/app/python
COMMENT=	GeoIP support for Python

USE_BUILDLINK3=	yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
