# $NetBSD: Makefile,v 1.9 2025/11/02 20:08:42 adam Exp $

DISTNAME=	lru_dict-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lru-dict/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/amitdev/lru-dict
COMMENT=	Dict-like LRU container
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80.9.0:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
