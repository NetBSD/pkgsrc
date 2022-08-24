# $NetBSD: Makefile,v 1.7 2022/08/24 09:50:58 wiz Exp $

DISTNAME=	sqlsoup-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlsoup/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://bitbucket.org/zzzeek/sqlsoup
COMMENT=	One step database access tool, built on the SQLAlchemy ORM
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7.0:../../databases/py-sqlalchemy
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0.11:../../devel/py-nose

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
