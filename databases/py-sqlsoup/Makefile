# $NetBSD: Makefile,v 1.1 2014/02/03 10:21:13 rodent Exp $

DISTNAME=	sqlsoup-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/s/sqlsoup/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://bitbucket.org/zzzeek/sqlsoup
COMMENT=	One step database access tool, built on the SQLAlchemy ORM
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7.10:../../databases/py-sqlalchemy

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_sqlsoup.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
