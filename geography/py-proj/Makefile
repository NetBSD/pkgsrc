# $NetBSD: Makefile,v 1.46 2024/05/29 16:32:48 adam Exp $

DISTNAME=		pyproj-3.2.1
# 3.3.0 requires proj 8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		9
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_PYPI:=p/pyproj/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://github.com/pyproj4/pyproj
COMMENT=		Python interface to PROJ.4 library
LICENSE=		mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../geography/proj/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
