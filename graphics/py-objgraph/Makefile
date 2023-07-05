# $NetBSD: Makefile,v 1.6 2023/07/05 12:02:37 adam Exp $

DISTNAME=	objgraph-3.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/objgraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mg.pov.lt/objgraph/
COMMENT=	Draws Python object reference graphs with graphviz
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-graphviz-[0-9]*:../../graphics/py-graphviz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
