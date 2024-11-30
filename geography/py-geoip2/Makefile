# $NetBSD: Makefile,v 1.5 2024/11/30 06:51:58 adam Exp $

DISTNAME=	geoip2-4.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geoip2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/
COMMENT=	MaxMind GeoIP2 API
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.6.2:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-maxminddb>=2.5.1:../../geography/py-maxminddb
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver>=1.0.10:../../devel/py-test-httpserver

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
