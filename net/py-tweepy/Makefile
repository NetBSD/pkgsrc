# $NetBSD: Makefile,v 1.12 2024/10/14 06:45:54 wiz Exp $

DISTNAME=	tweepy-3.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tweepy/}

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	https://github.com/tweepy/tweepy
COMMENT=	Basic Python API for Twitter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.11.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.7.0:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
