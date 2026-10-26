# $NetBSD: Makefile,v 1.178 2026/10/26 05:21:36 adam Exp $
#
# Changelog: https://hypothesis.readthedocs.io/en/latest/changes.html

DISTNAME=	hypothesis-6.170.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HypothesisWorks/hypothesis
COMMENT=	Python library for property based testing
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.1.0:../../devel/py-sortedcontainers

PY_RENAME_BINARIES=	hypothesis

RUST_REQ=	1.91

CARGO_WRKSRC=	${WRKSRC}/rust

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
