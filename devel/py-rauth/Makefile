# $NetBSD: Makefile,v 1.1 2017/03/17 20:44:38 darcy Exp $

DISTNAME=	rauth-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES= ${MASTER_SITE_PYPI:=r/rauth/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://github.com/litl/rauth
COMMENT=	Python library for OAuth 1.0/a, 2.0, and Ofly consumers

LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-nose>=1.2.1:../../devel/py-nose
DEPENDS+=   ${PYPKGPREFIX}-mock>=1.0.1:../../devel/py-mock
DEPENDS+=   ${PYPKGPREFIX}-crypto>=2.5:../../security/py-crypto

do-test:
	${CD} ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
