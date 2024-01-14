# $NetBSD: Makefile,v 1.3 2024/01/14 15:17:35 adam Exp $

DISTNAME=	geoip2-4.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geoip2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/
COMMENT=	MaxMind GeoIP2 API
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.6.2:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-maxminddb>=2.5.1:../../geography/py-maxminddb
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-setuptools>=60.0.0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-mocket>=3.11.1:../../devel/py-mocket

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
