# $NetBSD: Makefile,v 1.27 2026/10/16 17:43:15 adam Exp $

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

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
