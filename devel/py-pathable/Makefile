# $NetBSD: Makefile,v 1.2 2025/01/14 11:57:10 adam Exp $

DISTNAME=	pathable-0.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pathable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p1c2u/pathable
COMMENT=	Object-oriented paths
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
