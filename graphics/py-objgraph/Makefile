# $NetBSD: Makefile,v 1.10 2025/04/13 11:08:59 wiz Exp $

DISTNAME=	objgraph-3.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/objgraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mg.pov.lt/objgraph/
COMMENT=	Draws Python object reference graphs with graphviz
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-graphviz-[0-9]*:../../graphics/py-graphviz

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest tests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
