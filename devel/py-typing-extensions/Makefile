# $NetBSD: Makefile,v 1.11 2021/09/01 18:19:27 adam Exp $

DISTNAME=	typing_extensions-3.10.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing-extensions/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/python/typing
COMMENT=	Backported and Experimental Type Hints for Python
LICENSE=	python-software-foundation

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-typing>=3.7.4:../../devel/py-typing
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
