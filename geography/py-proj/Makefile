# $NetBSD: Makefile,v 1.32 2022/04/18 19:11:13 adam Exp $

DISTNAME=		pyproj-2.6.1
# After proj is >= 7
#DISTNAME=		pyproj-3.0.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_PYPI:=p/pyproj/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://github.com/pyproj4/pyproj
COMMENT=		Python interface to PROJ.4 library
LICENSE=		mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0:../../devel/py-cython

.include "../../geography/proj/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
