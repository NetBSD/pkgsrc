# $NetBSD: Makefile,v 1.52 2022/01/04 20:52:50 wiz Exp $

DISTNAME=	astroid-2.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
.if ${_PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typed-ast>=1.4.0:../../devel/py-typed-ast
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10:../../devel/py-typing-extensions
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
