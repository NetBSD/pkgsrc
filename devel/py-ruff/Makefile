# $NetBSD: Makefile,v 1.2 2023/11/13 11:28:07 wiz Exp $

DISTNAME=	ruff-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/charliermarsh/ruff
COMMENT=	Extremely fast Python linter, written in Rust
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=0.14.10:../../devel/py-maturin

# for tikv-jemalloc-sys
USE_TOOLS+=	gmake

MAKE_ENV+=	CARGO_NET_OFFLINE=true

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ruff ruff-${PYVERSSUFFIX}

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
