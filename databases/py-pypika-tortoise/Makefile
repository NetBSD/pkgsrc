# $NetBSD: Makefile,v 1.8 2025/01/14 09:54:43 wiz Exp $

DISTNAME=	pypika_tortoise-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypika-tortoise/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tortoise/pypika-tortoise
COMMENT=	Forked from pypika and streamline just for tortoise-orm
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.0.1:../../devel/py-poetry-core

CONFLICTS=	py[0-9]*-pypika-[0-9]*

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
