# $NetBSD: Makefile,v 1.1 2026/11/11 14:44:48 wiz Exp $

DISTNAME=	pwdlib-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pwdlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frankie567/pwdlib
COMMENT=	Modern password hashing for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi>=0:../../security/py-argon2-cffi
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=0:../../security/py-bcrypt
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
