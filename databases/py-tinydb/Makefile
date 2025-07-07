# $NetBSD: Makefile,v 1.5 2025/07/07 05:58:03 wiz Exp $

DISTNAME=	tinydb-4.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tinydb/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/msiemens/tinydb
COMMENT=	Tiny, document oriented database optimized for your happiness
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-[0-9]*:../../devel/py-poetry

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
