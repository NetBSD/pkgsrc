# $NetBSD: Makefile,v 1.8 2026/06/28 15:41:12 wiz Exp $

DISTNAME=	tinydb-4.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tinydb/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/msiemens/tinydb
COMMENT=	Tiny, document oriented database optimized for your happiness
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry>=2.1.4nb1:../../devel/py-poetry

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
