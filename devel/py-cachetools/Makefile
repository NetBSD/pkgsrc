# $NetBSD: Makefile,v 1.40 2026/08/08 06:08:39 adam Exp $

DISTNAME=	cachetools-7.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cachetools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tkem/cachetools
COMMENT=	Extensible memoizing collections and decorators
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.2:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
