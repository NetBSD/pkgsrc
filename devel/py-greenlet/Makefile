# $NetBSD: Makefile,v 1.20 2023/09/01 10:44:59 nia Exp $

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

# This does not use -std=cXX, but includes cstdint.
# When compiling with gcc 4.8, this causes an error due to not having
# explicitly enabled C++11 support.
FORCE_CXX_STD=		c++11
USE_CXX_FEATURES+=	c++11

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover greenlet.tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
