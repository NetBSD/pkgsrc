# $NetBSD: Makefile,v 1.4 2019/01/15 11:57:21 adam Exp $

DISTNAME=	typing_extensions-3.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing-extensions/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/python/typing
COMMENT=	Backported and Experimental Type Hints for Python
LICENSE=	python-software-foundation

PLIST_VARS+=	requires

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27 || ${_PYTHON_VERSION} == 34
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
PLIST.requires=	yes
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
