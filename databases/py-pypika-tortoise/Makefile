# $NetBSD: Makefile,v 1.1 2023/11/23 07:56:01 adam Exp $

DISTNAME=	pypika-tortoise-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypika-tortoise/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tortoise/pypika-tortoise
COMMENT=	Forked from pypika and streamline just for tortoise-orm
LICENSE=	apache-2.0

CONFLICTS=	${PYPKGPREFIX}-pypika-[0-9]*

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
