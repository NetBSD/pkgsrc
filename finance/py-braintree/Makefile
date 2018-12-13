# $NetBSD: Makefile,v 1.15 2018/12/13 07:13:28 adam Exp $

DISTNAME=	braintree-3.50.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/braintree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/braintree/braintree_python
COMMENT=	Braintree Python Library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=0.11.1:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
