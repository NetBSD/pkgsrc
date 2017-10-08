# $NetBSD: Makefile,v 1.10 2017/10/08 08:58:21 adam Exp $

DISTNAME=	bcrypt-3.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/bcrypt
COMMENT=	Modern password hashing for your software and your servers
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.1:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

CONFLICTS+=	${PYPKGPREFIX}-py-bcrypt-[0-9]*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
