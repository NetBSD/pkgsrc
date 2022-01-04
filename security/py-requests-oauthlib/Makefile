# $NetBSD: Makefile,v 1.12 2022/01/04 20:54:44 wiz Exp $

DISTNAME=	requests-oauthlib-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
