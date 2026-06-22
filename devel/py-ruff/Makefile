# $NetBSD: Makefile,v 1.112 2026/06/22 09:55:37 adam Exp $

DISTNAME=	ruff-0.15.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/ruff
COMMENT=	Extremely fast Python linter, written in Rust
LICENSE=	mit

USE_LANGUAGES=	c c++
RUST_REQ=	1.94

# for tikv-jemalloc-sys
USE_TOOLS+=	gmake

MAKE_ENV+=	CARGO_NET_OFFLINE=true

PY_RENAME_BINARIES=	ruff

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/ruff/_find_ruff.py.orig

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
