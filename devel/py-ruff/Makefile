# $NetBSD: Makefile,v 1.105 2026/04/26 21:01:14 wiz Exp $

DISTNAME=	ruff-0.15.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/ruff
COMMENT=	Extremely fast Python linter, written in Rust
LICENSE=	mit

USE_LANGUAGES=	c c++
RUST_REQ=	1.92

# for tikv-jemalloc-sys
USE_TOOLS+=	gmake

CARGO_GITHUB_CRATES+=	astral-sh lsp-types e15db0593f0ecbbd80599c3f5880e4bf5da1ca0c

MAKE_ENV+=	CARGO_NET_OFFLINE=true

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/ruff/_find_ruff.py.orig
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ruff ruff-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
