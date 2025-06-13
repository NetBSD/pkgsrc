# $NetBSD: Makefile,v 1.10 2025/06/13 07:10:11 adam Exp $

DISTNAME=	argon2_cffi-25.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argon2-cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://argon2-cffi.readthedocs.io/
COMMENT=	Secure Argon2 password hashing algorithm
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi-bindings-[0-9]*:../../security/py-argon2-cffi-bindings
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none

MAKE_ENV+=	ARGON2_CFFI_USE_SYSTEM=1

.include "../../lang/python/wheel.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
