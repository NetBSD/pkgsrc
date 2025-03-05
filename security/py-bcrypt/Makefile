# $NetBSD: Makefile,v 1.28 2025/03/05 13:43:12 adam Exp $

DISTNAME=	bcrypt-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/bcrypt
COMMENT=	Modern password hashing for your software and your servers
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42.0.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.7.0:../../devel/py-setuptools-rust

CARGO_WRKSRC=	${WRKSRC}/src/_bcrypt/

CHECK_WRKREF_SKIP+=	lib/python*/site-packages/bcrypt/_bcrypt.so

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
