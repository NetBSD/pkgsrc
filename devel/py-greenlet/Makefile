# $NetBSD: Makefile,v 1.26 2024/10/07 22:57:12 wiz Exp $

DISTNAME=	greenlet-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/greenlet/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/python-greenlet/greenlet
COMMENT=	Lightweight in-process concurrent programming
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.8.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-objgraph-[0-9]*:../../graphics/py-objgraph
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

USE_LANGUAGES=	c c++

# This does not use -std=cXX, but includes cstdint.
# When compiling with gcc 4.8, this causes an error due to not having
# explicitly enabled C++11 support.
#FORCE_CXX_STD=		c++11
USE_CXX_FEATURES+=	c++11

# sorry, unimplemented: non-trivial designated initializers not supported
GCC_REQD+=		8

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
