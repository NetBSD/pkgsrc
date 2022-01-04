# $NetBSD: Makefile,v 1.8 2022/01/04 20:54:34 wiz Exp $

DISTNAME=	twython-3.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twython/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/ryanmcgrath/twython
COMMENT=	Python wrapper for the Twitter API
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.4.0:../../security/py-requests-oauthlib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
