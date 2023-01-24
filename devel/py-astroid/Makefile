# $NetBSD: Makefile,v 1.70 2023/01/24 10:07:28 adam Exp $

DISTNAME=	astroid-2.13.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroid/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/pycqa/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.37.1:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy>=1.4.0:../../devel/py-lazy-object-proxy
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.14:../../devel/py-wrapt

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} != 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0.0:../../devel/py-typing-extensions
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
