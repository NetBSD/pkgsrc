# $NetBSD: Makefile,v 1.13 2016/06/08 17:43:22 wiz Exp $

DISTNAME=	sqlalchemy-migrate-0.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sqlalchemy-migrate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stackforge/sqlalchemy-migrate
COMMENT=	Schema migration tool for SQLAlchemy
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
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

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
