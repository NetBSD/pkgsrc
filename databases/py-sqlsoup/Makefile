# $NetBSD: Makefile,v 1.3 2017/07/16 19:42:32 adam Exp $

DISTNAME=	sqlsoup-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlsoup/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://bitbucket.org/zzzeek/sqlsoup
COMMENT=	One step database access tool, built on the SQLAlchemy ORM
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7.0:../../databases/py-sqlalchemy
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose>=0.11:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
