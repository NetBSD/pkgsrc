# $NetBSD: Makefile,v 1.11 2024/10/14 06:45:55 wiz Exp $

DISTNAME=	twython-3.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twython/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/ryanmcgrath/twython
COMMENT=	Python wrapper for the Twitter API
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.4.0:../../security/py-requests-oauthlib

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
