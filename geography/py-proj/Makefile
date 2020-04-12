# $NetBSD: Makefile,v 1.21 2020/04/12 08:28:47 adam Exp $

DISTNAME=		pyproj-2.6.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_PYPI:=p/pyproj/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://github.com/pyproj4/pyproj
COMMENT=		Python interface to PROJ.4 library
LICENSE=		mit

.include "../../geography/proj/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
