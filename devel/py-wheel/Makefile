# $NetBSD: Makefile,v 1.45 2026/04/24 11:08:02 adam Exp $

DISTNAME=	wheel-0.47.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/wheel
COMMENT=	Tool for manipulating Python wheel files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-packaging>=24.0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=77:../../devel/py-setuptools

USE_LANGUAGES=	c # for tests only

PY_RENAME_BINARIES=	wheel

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
