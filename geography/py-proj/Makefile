# $NetBSD: Makefile,v 1.57 2025/04/24 14:14:09 wiz Exp $

DISTNAME=	pyproj-3.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	7
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyproj/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/pyproj4/pyproj
COMMENT=	Python interface to PROJ.4 library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

# tests fail
# https://github.com/pyproj4/pyproj/issues/1447

.include "../../geography/proj/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
