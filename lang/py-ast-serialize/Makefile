# $NetBSD: Makefile,v 1.9 2026/09/23 07:46:41 adam Exp $

DISTNAME=	ast_serialize-0.11.2
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
