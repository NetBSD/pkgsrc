# $NetBSD: Makefile,v 1.8 2025/04/12 11:55:00 adam Exp $

DISTNAME=	lru-dict-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lru-dict/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/amitdev/lru-dict
COMMENT=	Dict-like LRU container
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
