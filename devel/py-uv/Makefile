# $NetBSD: Makefile,v 1.4 2026/04/14 12:09:05 adam Exp $

DISTNAME=	uv-${UV_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv/}

COMMENT=	Extremely fast Python package and project manager

USE_TOOLS+=	gmake

.include "Makefile.common"

PY_RENAME_BINARIES=	uv uvx

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
