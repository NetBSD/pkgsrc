# $NetBSD: Makefile,v 1.22 2024/01/04 22:38:08 adam Exp $

DISTNAME=	frozendict-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/frozendict/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/Marco-Sulla/python-frozendict
COMMENT=	Immutable wrapper around dictionaries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

MAKE_ENV+=	FROZENDICT_PURE_PY=1

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
