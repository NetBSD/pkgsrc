# $NetBSD: Makefile,v 1.34 2026/08/09 06:12:46 adam Exp $

DISTNAME=	pybind11-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybind11/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pybind/pybind11
COMMENT=	Seamless operability between C++11 and Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core>=0.11.2:../../devel/py-scikit-build-core
TOOL_DEPENDS+=	cmake>=3.15:../../devel/cmake

USE_LANGUAGES=	c c++

PY_RENAME_BINARIES=	pybind11-config

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
