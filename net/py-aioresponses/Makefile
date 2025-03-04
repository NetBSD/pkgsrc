# $NetBSD: Makefile,v 1.13 2025/03/04 09:15:06 wiz Exp $

DISTNAME=	aioresponses-0.7.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aioresponses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pnuckowski/aioresponses
COMMENT=	Mock out requests made by ClientSession from aiohttp package
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.3.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-packaging>=22.0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-ddt>=1.4.1:../../devel/py-ddt
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx via py-pbr

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
