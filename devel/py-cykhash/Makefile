# $NetBSD: Makefile,v 1.6 2025/04/12 10:14:29 adam Exp $

DISTNAME=	cykhash-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cykhash/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/realead/cykhash
COMMENT=	Cython equivalent to khash-sets/maps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
