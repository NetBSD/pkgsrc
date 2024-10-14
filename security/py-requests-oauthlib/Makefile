# $NetBSD: Makefile,v 1.17 2024/10/14 06:45:57 wiz Exp $

DISTNAME=	requests-oauthlib-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-oauthlib/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-oauthlib
COMMENT=	OAuthlib support for Python-Requests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=3.0.0:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-selenium-[0-9]*:../../www/py-selenium
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
