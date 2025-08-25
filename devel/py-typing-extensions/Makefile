# $NetBSD: Makefile,v 1.32 2025/08/25 17:57:45 adam Exp $

DISTNAME=	typing_extensions-4.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing-extensions/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/python/typing
COMMENT=	Backported and Experimental Type Hints for Python
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

# as of 4.14.0
# 1 failed, 532 passed, 10 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
