# $NetBSD: Makefile,v 1.18 2024/04/03 07:17:51 adam Exp $

DISTNAME=	ruff-0.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/ruff
COMMENT=	Extremely fast Python linter, written in Rust
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1.0:../../devel/py-maturin

# for tikv-jemalloc-sys
USE_TOOLS+=	gmake

MAKE_ENV+=	CARGO_NET_OFFLINE=true

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ruff ruff-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
