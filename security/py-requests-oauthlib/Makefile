# $NetBSD: Makefile,v 1.2 2014/05/13 17:08:45 joerg Exp $

DISTNAME=	requests-oauthlib-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S,-,_,}
CATEGORIES=	security
MASTER_SITES=	https://pypi.python.org/packages/source/r/requests-oauthlib/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-oauthlib
COMMENT=	OAuthlib support for Python-Requests
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests>=2.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=0.6.1:../../security/py-oauthlib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
