# $NetBSD: Makefile,v 1.5 2025/04/20 19:58:07 wiz Exp $

DISTNAME=	boolean_py-5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boolean.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bastikr/boolean.py
COMMENT=	Define boolean algebras, create and parse boolean expressions and create custom boolean DSL
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
