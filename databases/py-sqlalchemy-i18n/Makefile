# $NetBSD: Makefile,v 1.10 2025/02/07 13:53:43 adam Exp $

DISTNAME=	SQLAlchemy-i18n-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy-i18n/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/sqlalchemy-i18n
COMMENT=	Internationalization extension for SQLAlchemy models
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.3:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-utils>=0.37.3:../../databases/py-sqlalchemy-utils
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-flexmock>=0.9.7:../../devel/py-flexmock
TEST_DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.4.6:../../databases/py-psycopg2
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=2.4.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-isort>=3.9.6:../../devel/py-isort

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
