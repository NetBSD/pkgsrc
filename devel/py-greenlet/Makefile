# $NetBSD: Makefile,v 1.43 2026/06/29 05:29:34 adam Exp $

DISTNAME=	greenlet-3.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/greenlet/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/python-greenlet/greenlet
COMMENT=	Lightweight in-process concurrent programming
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-objgraph-[0-9]*:../../graphics/py-objgraph
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++

# sorry, unimplemented: non-trivial designated initializers not supported
GCC_REQD+=		8

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
