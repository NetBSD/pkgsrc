# $NetBSD: Makefile,v 1.42 2021/04/26 12:58:24 adam Exp $

DISTNAME=	astroid-2.5.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroid/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/pycqa/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy>=1.4.0:../../devel/py-lazy-object-proxy
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.11:../../devel/py-wrapt

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typed-ast>=1.4.0:../../devel/py-typed-ast
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
