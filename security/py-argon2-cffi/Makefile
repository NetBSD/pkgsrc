# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:37 wiz Exp $

DISTNAME=	argon2-cffi-20.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argon2-cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://argon2-cffi.readthedocs.io/
COMMENT=	Secure Argon2 password hashing algorithm
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES=	test:test
PYTHON_VERSIONED_DEPENDENCIES+=	hypothesis:test

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

MAKE_ENV+=	ARGON2_CFFI_USE_SYSTEM=1

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
