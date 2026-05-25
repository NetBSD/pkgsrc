# $NetBSD: Makefile,v 1.2 2026/05/25 10:51:51 adam Exp $

DISTNAME=	ast_serialize-0.5.0
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
