# $NetBSD: Makefile,v 1.61 2025/10/05 19:26:01 js Exp $

DISTNAME=	pyproj-3.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyproj/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/pyproj4/pyproj
COMMENT=	Python interface to PROJ.4 library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

# tests fail
# https://github.com/pyproj4/pyproj/issues/1447

.include "../../geography/proj/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
