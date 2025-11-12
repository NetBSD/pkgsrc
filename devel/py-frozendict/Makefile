# $NetBSD: Makefile,v 1.31 2025/11/12 09:02:43 adam Exp $

DISTNAME=	frozendict-2.4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/frozendict/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/Marco-Sulla/python-frozendict
COMMENT=	Immutable wrapper around dictionaries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

MAKE_ENV+=	FROZENDICT_PURE_PY=1

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
