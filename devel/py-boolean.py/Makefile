# $NetBSD: Makefile,v 1.3 2025/03/03 06:56:29 wiz Exp $

DISTNAME=	boolean.py-4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boolean.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bastikr/boolean.py
COMMENT=	Define boolean algebras, create and parse boolean expressions and create custom boolean DSL
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:S/n.p/n_p/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
