# $NetBSD: Makefile,v 1.9 2025/03/04 13:05:19 adam Exp $

.include "../../devel/thrift/Makefile.version"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python
COMMENT=	Python bindings for the Apache Thrift RPC system

EXTRACT_ELEMENTS=	${DISTNAME}/lib/py

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=1.7.2:../../lang/py-six
# all
DEPENDS+=	${PYPKGPREFIX}-tornado>=4:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-scons>=4:../../devel/scons4

USE_LANGUAGES=	c c++
PYSETUPSUBDIR=	lib/py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
