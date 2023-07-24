# $NetBSD: Makefile,v 1.8 2023/07/24 17:41:40 wiz Exp $

PKGREVISION= 2
.include "../../devel/thrift/Makefile.version"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python
COMMENT=	Python bindings for the Apache Thrift RPC system

EXTRACT_ELEMENTS=	${DISTNAME}/lib/py

DEPENDS+=	${PYPKGPREFIX}-six>=1.7.2:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tornado>=4:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-scons>=4:../../devel/scons4

USE_LANGUAGES=	c c++
PYSETUPSUBDIR=	lib/py

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
