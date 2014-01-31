# $NetBSD: Makefile,v 1.1 2014/01/31 12:30:50 rodent Exp $

DISTNAME=	trytond-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://downloads.tryton.org/3.0/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Server of the Tryton application platform
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	trytond/tests/test_access.py trytond/tests/test_cache.py
REPLACE_PYTHON+=	trytond/tests/test_copy.py
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

.include "options.mk"

DEPENDS+=	${PYPKGPREFIX}-python-sql>=0.2:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
.include "../../lang/python/pyversion.mk"
.if ${PYPACKAGE} == "python27"
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
.else
DEPENDS+=	${PYPKGPREFIX}-dateutil2-[0-9]*:../../time/py-dateutil2
.endif
DEPENDS+=	${PYPKGPREFIX}-relatorio>=0.2.0:../../textproc/py-relatorio
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0:../../textproc/py-lxml
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
