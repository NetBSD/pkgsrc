# $NetBSD: Makefile,v 1.48 2024/09/05 00:01:55 gdt Exp $

DISTNAME=		pyproj-3.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
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
