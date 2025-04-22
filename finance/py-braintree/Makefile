# $NetBSD: Makefile,v 1.64 2025/04/22 15:33:29 adam Exp $

DISTNAME=	braintree-4.34.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/braintree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/braintree/braintree_python
COMMENT=	Braintree Python Library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=0.11.1:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
