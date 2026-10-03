# $NetBSD: Makefile,v 1.26 2026/10/03 09:14:41 adam Exp $

DISTNAME=	debugpy-1.8.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/debugpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/debugpy
COMMENT=	Implementation of the Debug Adapter Protocol for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PY_RENAME_BINARIES=	debugpy debugpy-adapter

PLIST_VARS+=	frame_eval pydevd_cython
.include "../../lang/python/pyversion.mk"

# pydevd_frame_evaluator is not available for Python 3.11
# see src/debugpy/_vendored/pydevd/setup_pydevd_cython.py
.if ${PYTHON_VERSION} < 311
PLIST.frame_eval=	yes
.endif
.if ${PYTHON_VERSION} >= 312
PLIST.pydevd_cython=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
