# $NetBSD: Makefile,v 1.14 2025/11/24 12:50:50 adam Exp $

DISTNAME=	altgraph-0.17.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/altgraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://altgraph.readthedocs.io/
COMMENT=	Graph (network) package for constructing graphs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
