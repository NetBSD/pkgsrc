# $NetBSD: Makefile,v 1.1 2018/08/19 09:40:37 adam Exp $

DISTNAME=	objgraph-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/objgraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mg.pov.lt/objgraph/
COMMENT=	Draws Python object reference graphs with graphviz
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-graphviz-[0-9]*:../../graphics/py-graphviz
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
