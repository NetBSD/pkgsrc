# $NetBSD: Makefile,v 1.7 2024/11/11 07:28:15 wiz Exp $

DISTNAME=	lru-dict-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lru-dict/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/amitdev/lru-dict
COMMENT=	Dict-like LRU container
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
