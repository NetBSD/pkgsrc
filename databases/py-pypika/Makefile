# $NetBSD: Makefile,v 1.30 2025/10/09 10:56:26 wiz Exp $

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

# ast.Str, see https://github.com/kayak/pypika/issues/847
PYTHON_VERSIONS_INCOMPATIBLE+=	314

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
