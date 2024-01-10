# $NetBSD: Makefile,v 1.2 2024/01/10 14:32:28 wiz Exp $

DISTNAME=	cykhash-2.0.1
PKGNAME=	${PYPKGPREFIX}-cykhash-2.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cykhash/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pypi.python.org/project/cykhash/
COMMENT=	Cython equivalent to khash-sets/maps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
