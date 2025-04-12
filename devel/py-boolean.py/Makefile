# $NetBSD: Makefile,v 1.4 2025/04/12 09:39:48 adam Exp $

DISTNAME=	boolean.py-4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boolean.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bastikr/boolean.py
COMMENT=	Define boolean algebras, create and parse boolean expressions and create custom boolean DSL
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:S/n.p/n_p/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
