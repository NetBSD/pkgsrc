# $NetBSD: Makefile,v 1.19 2022/01/04 20:52:44 wiz Exp $

DISTNAME=	sqlalchemy-migrate-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlalchemy-migrate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stackforge/sqlalchemy-migrate
COMMENT=	Schema migration tool for SQLAlchemy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tempita>=0.4:../../textproc/py-Tempita
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7.8:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlparse-[0-9]*:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six>=1.7.0:../../lang/py-six

USE_LANGUAGES=		# none

REPLACE_PYTHON+=	migrate/tests/changeset/databases/test_ibmdb2.py
REPLACE_PYTHON+=	migrate/tests/changeset/test_changeset.py
REPLACE_PYTHON+=	migrate/tests/changeset/test_constraint.py
REPLACE_PYTHON+=	migrate/tests/fixture/__init__.py
REPLACE_PYTHON+=	migrate/tests/fixture/base.py
REPLACE_PYTHON+=	migrate/tests/fixture/database.py
REPLACE_PYTHON+=	migrate/tests/fixture/pathed.py
REPLACE_PYTHON+=	migrate/tests/fixture/shell.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_api.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_cfgparse.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_keyedinstance.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_repository.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_runchangeset.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_schema.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_script.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_shell.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_template.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_util.py
REPLACE_PYTHON+=	migrate/tests/versioning/test_version.py
REPLACE_PYTHON+=	migrate/versioning/config.py
REPLACE_PYTHON+=	migrate/versioning/script/*.py
REPLACE_PYTHON+=	migrate/versioning/shell.py
REPLACE_PYTHON+=	migrate/versioning/template.py
REPLACE_PYTHON+=	migrate/versioning/templates/manage/*.py_tmpl
REPLACE_PYTHON+=	migrate/versioning/util/__init__.py
REPLACE_PYTHON+=	migrate/versioning/util/keyedinstance.py
REPLACE_PYTHON+=	migrate/versioning/version.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} migrate migrate-${PYVERSSUFFIX} && \
	${MV} migrate-repository migrate-repository-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
