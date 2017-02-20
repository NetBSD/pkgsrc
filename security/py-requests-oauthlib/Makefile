# $NetBSD: Makefile,v 1.7 2017/02/20 10:00:08 wiz Exp $

DISTNAME=	requests-oauthlib-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-oauthlib/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-oauthlib
COMMENT=	OAuthlib support for Python-Requests
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=0.6.1:../../security/py-oauthlib
# BUILD_DEPENDS+=requests-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr>=0.11:../../devel/py-pbr

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
