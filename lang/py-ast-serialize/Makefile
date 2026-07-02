# $NetBSD: Makefile,v 1.3 2026/07/02 11:24:09 adam Exp $

DISTNAME=	ast_serialize-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ast-serialize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mypyc/ast_serialize
COMMENT=	Python bindings for mypy AST serialization
LICENSE=	mit

CARGO_GITHUB_CRATES+=	astral-sh ruff 0.15.12
# Done in patch-Cargo.toml
SUBST_NOOP_OK.gitcrate=	yes

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
