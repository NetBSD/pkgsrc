# $NetBSD: Makefile,v 1.7 2026/09/09 08:10:17 adam Exp $

DISTNAME=	ast_serialize-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ast-serialize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mypyc/ast_serialize
COMMENT=	Python bindings for mypy AST serialization
LICENSE=	mit

RUST_REQ=	1.80

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
