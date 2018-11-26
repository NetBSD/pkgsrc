# $NetBSD: Makefile,v 1.22 2018/11/26 09:00:52 adam Exp $

DISTNAME=	astroid-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroid/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/pycqa/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy-[0-9]*:../../devel/py-lazy-object-proxy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-wrapt-[0-9]*:../../devel/py-wrapt
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

.include "../../lang/python/pyversion.mk"
.if !empty(_PYTHON_VERSION:M34)
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif
.if !empty(_PYTHON_VERSION:M3[456])
DEPENDS+=	${PYPKGPREFIX}-typed-ast-[0-9]*:../../devel/py-typed-ast
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
