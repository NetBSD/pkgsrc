# $NetBSD: Makefile,v 1.13 2022/02/06 19:04:17 adam Exp $

DISTNAME=	requests-oauthlib-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-oauthlib/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-oauthlib
COMMENT=	OAuthlib support for Python-Requests
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-oauthlib>=3.0.0:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-JWT

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
