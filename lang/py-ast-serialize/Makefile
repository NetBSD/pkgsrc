# $NetBSD: Makefile,v 1.14 2026/11/04 12:50:47 wiz Exp $

DISTNAME=	ast_serialize-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ast-serialize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mypyc/ast_serialize
COMMENT=	Python bindings for mypy AST serialization
LICENSE=	mit

RUST_REQ=	1.80

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && ${PYTHON_VERSION} >= 315
PYSTABLEABI=	abi3t-darwin
.endif

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
