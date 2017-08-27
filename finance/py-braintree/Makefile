# $NetBSD: Makefile,v 1.2 2017/08/27 12:14:41 adam Exp $

DISTNAME=	braintree-3.38.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/braintree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.braintreepayments.com/python/sdk/server/overview
COMMENT=	Braintree Python Library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=0.11.1:../../devel/py-requests

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
