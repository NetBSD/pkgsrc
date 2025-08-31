# $NetBSD: Makefile,v 1.76 2025/08/31 10:24:01 wiz Exp $

DISTNAME=	ruff-0.12.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/ruff
COMMENT=	Extremely fast Python linter, written in Rust
LICENSE=	mit

USE_LANGUAGES=	c c++

RUST_REQ=	1.87

# for tikv-jemalloc-sys
USE_TOOLS+=	gmake

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
LSP_TYPES_REV=	3512a9f33eadc5402cfab1b8f7340824c8ca1439
SALSA_REV=	a3ffa22cb26756473d56f867aedec3fd907c4dd9
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	lsp-types-${LSP_TYPES_REV}.tar.gz
DISTFILES+=	salsa-${SALSA_REV}.tar.gz

SITES.lsp-types-${LSP_TYPES_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=astral-sh/}lsp-types/archive/${LSP_TYPES_REV}.tar.gz
SITES.salsa-${SALSA_REV}.tar.gz+=		-${MASTER_SITE_GITHUB:=salsa-rs/}salsa/archive/${SALSA_REV}.tar.gz

MAKE_ENV+=	CARGO_NET_OFFLINE=true

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/ruff/__main__.py.orig
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ruff ruff-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
