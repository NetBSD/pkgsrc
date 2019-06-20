# $NetBSD: Makefile,v 1.14 2019/06/20 11:15:18 adam Exp $

DISTNAME=	bcrypt-3.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/bcrypt
COMMENT=	Modern password hashing for your software and your servers
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.1:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.4.0:../../devel/py-test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
