# $NetBSD: Makefile,v 1.11 2026/10/20 05:01:51 adam Exp $

DISTNAME=	funcparserlib-1.0.1
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/funcparserlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vlasovskikh/funcparserlib
COMMENT=	Recursive descent parsing library based on functional combinators
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
