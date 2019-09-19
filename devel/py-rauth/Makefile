# $NetBSD: Makefile,v 1.2 2019/09/19 19:06:30 adam Exp $

DISTNAME=	rauth-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rauth/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://github.com/litl/rauth
COMMENT=	Python library for OAuth 1.0/a, 2.0, and Ofly consumers
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.3:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
