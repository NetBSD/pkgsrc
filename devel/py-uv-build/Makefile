# $NetBSD: Makefile,v 1.8 2026/04/14 12:09:05 adam Exp $

DISTNAME=	uv_build-${UV_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv-build/}

COMMENT=	The uv build backend

.include "../../devel/py-uv/Makefile.common"

PY_RENAME_BINARIES=	uv-build

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/uv_build/__init__.py.orig

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
