# $NetBSD: Makefile,v 1.3 2018/10/14 16:21:04 adam Exp $

DISTNAME=	typing_extensions-3.6.6
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
