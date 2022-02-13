# $NetBSD: Makefile,v 1.6 2022/02/13 08:53:43 wiz Exp $

PKGREVISION= 1
.include "../../devel/thrift/Makefile.version"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python
COMMENT=	Python bindings for the Apache Thrift RPC system

EXTRACT_ELEMENTS=	${DISTNAME}/lib/py

DEPENDS+=	${PYPKGPREFIX}-six>=1.7.2:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-scons-[0-9]*:../../devel/scons

PYTHON_VERSIONED_DEPENDENCIES+=	twisted:test

USE_LANGUAGES=	c c++
PYSETUPSUBDIR=	lib/py

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
