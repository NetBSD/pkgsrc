# $NetBSD: Makefile,v 1.5 2026/05/27 08:10:11 adam Exp $

DISTNAME=	repoze_lru-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/repoze.lru/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.repoze.org/
COMMENT=	Tiny LRU cache implementation and decorator
LICENSE=	original-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
