# $NetBSD: Makefile,v 1.6 2017/10/14 10:23:01 adam Exp $

DISTNAME=	tweepy-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tweepy/}

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	https://github.com/tweepy/tweepy
COMMENT=	Basic Python API for Twitter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.4.1:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-six>=1.7.3:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
