# $NetBSD: Makefile,v 1.2 2018/08/05 18:31:02 minskim Exp $

DISTNAME=	typing_extensions-3.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing-extensions/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/python/typing
COMMENT=	Backported and Experimental Type Hints for Python
LICENSE=	python-software-foundation

PLIST_VARS+=	requires

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27" || "${PYPKGPREFIX}" == "py34"
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing

PLIST.requires=	yes
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
