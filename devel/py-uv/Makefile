# $NetBSD: Makefile,v 1.5 2026/10/12 21:20:36 wiz Exp $

DISTNAME=	uv-${UV_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv/}

COMMENT=	Extremely fast Python package and project manager

USE_TOOLS+=	gmake

.include "Makefile.common"
.include "cargo-depends.mk"

PY_RENAME_BINARIES=	uv uvx

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
