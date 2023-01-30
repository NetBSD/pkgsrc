# $NetBSD: Makefile,v 1.18 2023/01/30 12:53:24 adam Exp $

DISTNAME=	greenlet-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/greenlet/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/python-greenlet/greenlet
COMMENT=	Lightweight in-process concurrent programming
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-objgraph-[0-9]*:../../graphics/py-objgraph

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover greenlet.tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
