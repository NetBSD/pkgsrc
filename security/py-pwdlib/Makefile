# $NetBSD: Makefile,v 1.2 2026/11/17 05:34:40 adam Exp $

DISTNAME=	pwdlib-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pwdlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frankie567/pwdlib
COMMENT=	Modern password hashing for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
# argon2
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi>=23.1.0:../../security/py-argon2-cffi
# bcrypt
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=4.1.2:../../security/py-bcrypt
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
