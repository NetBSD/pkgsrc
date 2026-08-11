# $NetBSD: Makefile,v 1.21 2026/08/11 05:42:12 adam Exp $

DISTNAME=	cbor2-6.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cbor2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cbor2.readthedocs.org/
COMMENT=	CBOR (de)serializer with extensive tag support
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=0:../../devel/py-setuptools-rust
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.4:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

PY_RENAME_BINARIES=	cbor2

CARGO_WRKSRC=	${WRKSRC}/rust
.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
