# $NetBSD: Makefile,v 1.69 2022/11/20 17:50:20 adam Exp $

DISTNAME=	astroid-2.12.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroid/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/pycqa/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy>=1.4.0:../../devel/py-lazy-object-proxy
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.14:../../devel/py-wrapt

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10:../../devel/py-typing-extensions
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
