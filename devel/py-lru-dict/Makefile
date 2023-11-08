# $NetBSD: Makefile,v 1.6 2023/11/08 14:12:26 adam Exp $

DISTNAME=	lru-dict-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lru-dict/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/amitdev/lru-dict
COMMENT=	Dict-like LRU container
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
