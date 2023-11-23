# $NetBSD: Makefile,v 1.25 2023/11/23 08:03:59 adam Exp $

DISTNAME=	PyPika-0.48.9
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyPika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kayak/pypika
COMMENT=	SQL query builder API for Python
LICENSE=	apache-2.0

CONFLICTS=	${PYPKGPREFIX}-pypika-tortoise-[0-9]*

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
