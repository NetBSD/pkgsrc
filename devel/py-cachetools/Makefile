# $NetBSD: Makefile,v 1.21 2025/01/30 08:25:49 adam Exp $

DISTNAME=	cachetools-5.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cachetools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tkem/cachetools
COMMENT=	Extensible memoizing collections and decorators
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=46.4.0:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
