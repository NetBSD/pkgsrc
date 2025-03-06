# $NetBSD: Makefile,v 1.5 2025/03/06 01:19:06 bacon Exp $

DISTNAME=	cykhash-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cykhash/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/realead/cykhash
COMMENT=	Cython equivalent to khash-sets/maps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
