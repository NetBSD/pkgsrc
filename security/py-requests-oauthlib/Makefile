# $NetBSD: Makefile,v 1.1 2014/05/08 15:25:54 imil Exp $

DISTNAME=	requests-oauthlib-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	https://pypi.python.org/packages/source/r/requests-oauthlib/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-oauthlib
COMMENT=	OAuthlib support for Python-Requests
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=0.6.1:../../security/py-oauthlib

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
