# $NetBSD: Makefile,v 1.3 2026/10/26 06:04:25 wiz Exp $

DISTNAME=	argon2_cffi_bindings-25.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/argon2-cffi-bindings/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hynek/argon2-cffi-bindings
COMMENT=	Low-level CFFI bindings for Argon2
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.1:../../devel/py-cffi

MAKE_ENV+=	ARGON2_CFFI_USE_SYSTEM=1

.include "../../lang/python/wheel.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
