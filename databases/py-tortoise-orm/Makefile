# $NetBSD: Makefile,v 1.6 2020/06/12 17:02:59 adam Exp $

DISTNAME=	tortoise-orm-0.16.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tortoise-orm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tortoise/tortoise-orm
COMMENT=	Easy async ORM for Python, built with relations in mind
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiosqlite>=0.11.0:../../databases/py-aiosqlite
DEPENDS+=	${PYPKGPREFIX}-iso8601>=0.1.12:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-pypika>=0.36.5:../../databases/py-pypika
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7:../../devel/py-typing-extensions
# accel
DEPENDS+=	${PYPKGPREFIX}-ciso8601>=2.1.2:../../time/py-ciso8601
DEPENDS+=	${PYPKGPREFIX}-rapidjson-[0-9]*:../../textproc/py-rapidjson
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.12.0:../../devel/py-uvloop

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
