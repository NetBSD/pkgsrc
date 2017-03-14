# $NetBSD: Makefile,v 1.4 2017/03/14 19:28:31 adam Exp $

DISTNAME=	twython-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twython/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/ryanmcgrath/twython
COMMENT=	Python wrapper for the Twitter API
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.4.0:../../security/py-requests-oauthlib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
