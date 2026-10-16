# $NetBSD: Makefile,v 1.11 2026/10/16 19:43:44 adam Exp $

DISTNAME=	tinydb-4.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tinydb/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/msiemens/tinydb
COMMENT=	Tiny, document oriented database optimized for your happiness
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
