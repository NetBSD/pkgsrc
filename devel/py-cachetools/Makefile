# $NetBSD: Makefile,v 1.24 2025/06/07 21:38:52 wiz Exp $

DISTNAME=	cachetools-6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cachetools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tkem/cachetools
COMMENT=	Extensible memoizing collections and decorators
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
