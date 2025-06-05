# $NetBSD: Makefile,v 1.11 2025/06/05 14:46:22 adam Exp $

DISTNAME=	pypika_tortoise-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypika-tortoise/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tortoise/pypika-tortoise
COMMENT=	Forked from pypika and streamline just for tortoise-orm
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.0.1:../../devel/py-poetry-core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
