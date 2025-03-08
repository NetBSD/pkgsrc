# $NetBSD: Makefile,v 1.39 2025/03/08 12:31:18 wiz Exp $

DISTNAME=	SQLAlchemy-Utils-0.41.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy-Utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/sqlalchemy-utils
COMMENT=	Various utility functions for SQLAlchemy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0:../../databases/py-sqlalchemy
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-flexmock>=0.9.7:../../devel/py-flexmock
# py-psycopg
TEST_DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.5.1:../../databases/py-psycopg2
# py-psycopg2cffi
# pg8000
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=2014.2:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-pymysql-[0-9]*:../../databases/py-pymysql
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=2.4.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.2:../../devel/py-isort
# pyodbc

#TEST_DEPENDS+=	${PYPKGPREFIX}-arrow>=0.3.4:../../time/py-arrow
#TEST_DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
#TEST_DEPENDS+=	${PYPKGPREFIX}-furl>=0.3.5:../../www/py-furl
#TEST_DEPENDS+=	${PYPKGPREFIX}-intervals>=0.2.4:../../math/py-intervals
#TEST_DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6<2.0:../../security/py-passlib
#TEST_DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=5.9.2:../../textproc/py-phonenumbers

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl:S/-/_/}

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
