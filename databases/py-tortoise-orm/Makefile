# $NetBSD: Makefile,v 1.38 2025/10/09 07:57:28 wiz Exp $

DISTNAME=	tortoise_orm-0.25.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tortoise-orm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tortoise/tortoise-orm
COMMENT=	Easy async ORM for Python, built with relations in mind
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-aiosqlite>=0.16.0:../../databases/py-aiosqlite
DEPENDS+=	${PYPKGPREFIX}-iso8601>=2.1.0:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-pypika-tortoise>=0.6.1:../../databases/py-pypika-tortoise
DEPENDS+=	${PYPKGPREFIX}-pytz>=2020.4:../../time/py-pytz
# accel
DEPENDS+=	${PYPKGPREFIX}-ciso8601>=2.1.2:../../time/py-ciso8601
DEPENDS+=	${PYPKGPREFIX}-orjson>=0:../../textproc/py-orjson
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.14.0:../../devel/py-uvloop

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
