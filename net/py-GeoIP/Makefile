# $NetBSD: Makefile,v 1.2 2004/07/22 09:16:04 recht Exp $
#

DISTNAME=	GeoIP-Python-1.2.0
PKGNAME=	${PYPKGPREFIX}-GeoIP-1.2.0
CATEGORIES=	net python
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
