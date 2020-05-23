# $NetBSD: Makefile,v 1.3 2020/05/23 20:01:55 adam Exp $

DISTNAME=	tortoise-orm-0.16.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tortoise-orm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tortoise/tortoise-orm
COMMENT=	Easy async ORM for Python, built with relations in mind
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiosqlite>=0.11.0:../../databases/py-aiosqlite
DEPENDS+=	${PYPKGPREFIX}-ciso8601>=2.1.2:../../time/py-ciso8601
DEPENDS+=	${PYPKGPREFIX}-pypika>=0.36.5:../../databases/py-pypika
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
