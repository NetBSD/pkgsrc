# $NetBSD: Makefile,v 1.8 2014/06/14 17:06:32 rodent Exp $

DISTNAME=	sqlalchemy-migrate-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/s/sqlalchemy-migrate/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stackforge/sqlalchemy-migrate
COMMENT=	Schema migration tool for SQLAlchemy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pbr>=0.5.21<1.0:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-Tempita>=0.4:../../textproc/py-Tempita
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7.8:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six

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

EGG_NAME=		${DISTNAME:S/-/_/1}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
