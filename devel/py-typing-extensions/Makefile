# $NetBSD: Makefile,v 1.15 2022/10/13 16:07:52 adam Exp $

DISTNAME=	typing_extensions-4.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_WHEEL:=typing-extensions/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/python/typing
COMMENT=	Backported and Experimental Type Hints for Python
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# XXX: Avoid building and dependency to py-flit_core to avoid possible
# XXX: recursive dependency in py-build on Python 3.7:
# XXX:  py-build -> py-importlib-metadata -> py-typing-extenisons -> py-build
NO_BUILD=	yes
#TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
