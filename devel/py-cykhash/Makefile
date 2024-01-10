# $NetBSD: Makefile,v 1.1 2024/01/10 14:22:24 bacon Exp $

DISTNAME=	cykhash-2.0.1
PKGNAME=	${PYPKGPREFIX}-cykhash-2.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cykhash/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pypi.python.org/project/cykhash/
COMMENT=	Cython equivalent to khash-sets/maps
LICENSE=	mit

.include "../../lang/python/wheel.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
