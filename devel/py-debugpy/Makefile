# $NetBSD: Makefile,v 1.28 2026/10/17 13:47:57 wiz Exp $

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

.include "../../lang/python/pyversion.mk"

PLIST_VARS+=		pydevd_cython
.if ${PYTHON_VERSION} >= 312
PLIST.pydevd_cython=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
