# $NetBSD: Makefile,v 1.3 2021/01/11 13:58:09 adam Exp $

DISTNAME=	objgraph-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/objgraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mg.pov.lt/objgraph/
COMMENT=	Draws Python object reference graphs with graphviz
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-graphviz-[0-9]*:../../graphics/py-graphviz

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
