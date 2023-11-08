# $NetBSD: Makefile,v 1.41 2023/11/08 13:19:25 wiz Exp $

DISTNAME=		pyproj-3.2.1
# 3.3.0 requires proj 8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_PYPI:=p/pyproj/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://github.com/pyproj4/pyproj
COMMENT=		Python interface to PROJ.4 library
LICENSE=		mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0:../../devel/py-cython

.include "../../geography/proj/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
