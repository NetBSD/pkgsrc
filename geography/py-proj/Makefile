# $NetBSD: Makefile,v 1.23 2020/05/04 12:20:28 gdt Exp $

DISTNAME=		pyproj-2.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_PYPI:=p/pyproj/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://github.com/pyproj4/pyproj
COMMENT=		Python interface to PROJ.4 library
LICENSE=		mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0:../../devel/py-cython

.include "../../geography/proj/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
