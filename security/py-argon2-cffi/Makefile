# $NetBSD: Makefile,v 1.7 2023/05/05 08:33:05 adam Exp $

DISTNAME=	argon2-cffi-21.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argon2-cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://argon2-cffi.readthedocs.io/
COMMENT=	Secure Argon2 password hashing algorithm
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.4:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi-bindings-[0-9]*:../../security/py-argon2-cffi-bindings
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=	ARGON2_CFFI_USE_SYSTEM=1

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
