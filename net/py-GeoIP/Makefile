# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:29 joerg Exp $
#

DISTNAME=	GeoIP-Python-1.2.0
PKGNAME=	${PYPKGPREFIX}-GeoIP-1.2.0
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/python/

MAINTAINER=	bartosz@atom.eu.org
HOMEPAGE=	http://www.maxmind.com/app/python
COMMENT=	GeoIP support for Python

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
