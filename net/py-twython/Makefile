# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:37 wiz Exp $

DISTNAME=	twython-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twython/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/ryanmcgrath/twython
COMMENT=	Python wrapper for the Twitter API
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.4.0:../../security/py-requests-oauthlib

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
