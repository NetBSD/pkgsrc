# $NetBSD: Makefile,v 1.14 2026/03/27 10:20:06 adam Exp $

DISTNAME=	pypika_tortoise-0.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypika-tortoise/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tortoise/pypika-tortoise
COMMENT=	Forked from pypika and streamline just for tortoise-orm
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>0:../../devel/py-pdm_backend

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
