# $NetBSD: Makefile,v 1.13 2022/01/04 20:52:55 wiz Exp $

DISTNAME=	cachetools-4.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cachetools/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tkem/cachetools
COMMENT=	Extensible memoizing collections and decorators
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
