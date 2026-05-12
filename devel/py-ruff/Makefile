# $NetBSD: Makefile,v 1.106 2026/05/12 09:59:22 adam Exp $

DISTNAME=	ruff-0.15.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/ruff
COMMENT=	Extremely fast Python linter, written in Rust
LICENSE=	mit

USE_LANGUAGES=	c c++
RUST_REQ=	1.93

# for tikv-jemalloc-sys
USE_TOOLS+=	gmake

CARGO_GITHUB_CRATES+=	astral-sh lsp-types e15db0593f0ecbbd80599c3f5880e4bf5da1ca0c

MAKE_ENV+=	CARGO_NET_OFFLINE=true

PY_RENAME_BINARIES=	ruff

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/ruff/_find_ruff.py.orig

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
