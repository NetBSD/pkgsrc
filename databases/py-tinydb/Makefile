# $NetBSD: Makefile,v 1.10 2026/08/08 18:03:02 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
