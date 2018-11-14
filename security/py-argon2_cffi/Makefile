# $NetBSD: Makefile,v 1.3 2018/11/14 09:28:26 adam Exp $

DISTNAME=	argon2_cffi-18.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argon2_cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://argon2-cffi.readthedocs.io/
COMMENT=	Secure Argon2 password hashing algorithm
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

MAKE_ENV+=	ARGON2_CFFI_USE_SYSTEM=1

.include "../../lang/python/egg.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
