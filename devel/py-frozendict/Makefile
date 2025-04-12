# $NetBSD: Makefile,v 1.30 2025/04/12 10:59:19 adam Exp $

DISTNAME=	frozendict-2.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
