# $NetBSD: Makefile,v 1.13 2016/02/25 12:12:49 jperkin Exp $
TRYTON_MODULE_NAME=	trytond
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	devel python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Server of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql>=0.2:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
DEPENDS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-relatorio>=0.2.0:../../textproc/py-relatorio
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0:../../textproc/py-lxml

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	trytond/tests/run-tests.py trytond/tests/test_access.py
REPLACE_PYTHON+=	trytond/tests/test_cache.py trytond/tests/test_copy.py
REPLACE_PYTHON+=	trytond/tests/test_exportdata.py
REPLACE_PYTHON+=	trytond/tests/test_fields.py
REPLACE_PYTHON+=	trytond/tests/test_importdata.py
REPLACE_PYTHON+=	trytond/tests/test_mixins.py
REPLACE_PYTHON+=	trytond/tests/test_modelsingleton.py
REPLACE_PYTHON+=	trytond/tests/test_modelsql.py
REPLACE_PYTHON+=	trytond/tests/test_mptt.py trytond/tests/test_pyson.py
REPLACE_PYTHON+=	trytond/tests/test_sequence.py
REPLACE_PYTHON+=	trytond/tests/test_tools.py
REPLACE_PYTHON+=	trytond/tests/test_transaction.py
REPLACE_PYTHON+=	trytond/tests/test_trigger.py
REPLACE_PYTHON+=	trytond/tests/test_tryton.py

PYTHON_VERSIONED_DEPENDENCIES=	dateutil
PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

.include "options.mk"

OPSYSVARS+=		DEPENDS
DEPENDS.Darwin+=	${PYPKGPREFIX}-py2app-[0-9]*:../../devel/py-py2app

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/trytond \
		${DESTDIR}${PREFIX}/bin/trytond${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
