# $NetBSD: Makefile,v 1.20 2023/12/11 12:14:36 adam Exp $

DISTNAME=	bcrypt-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/bcrypt
COMMENT=	Modern password hashing for your software and your servers
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42.0.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=0:../../devel/py-setuptools-rust
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "cargo-depends.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/bcrypt/_bcrypt.abi3.so \
	${DESTDIR}${PREFIX}/${PYSITELIB}/bcrypt/_bcrypt.abi3.so
.endif

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
