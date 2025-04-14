# $NetBSD: Makefile,v 1.29 2025/04/14 11:31:12 adam Exp $

DISTNAME=	PyPika-0.48.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyPika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kayak/pypika
COMMENT=	SQL query builder API for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

CONFLICTS=	py[0-9]*-pypika-tortoise-[0-9]*

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
