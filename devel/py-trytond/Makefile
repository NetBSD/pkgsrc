# $NetBSD: Makefile,v 1.18 2017/02/20 17:00:35 wiz Exp $
TRYTON_MODULE_NAME=	trytond
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	devel python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Server of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-python-sql>=0.4:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
DEPENDS+=	${PYPKGPREFIX}-wrapt-[0-9]*:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-relatorio>=0.2.0:../../textproc/py-relatorio
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-genshi-[0-9]*:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

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

PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYPKGPREFIX=${PYPKGPREFIX}

.include "options.mk"

OPSYSVARS+=		DEPENDS
DEPENDS.Darwin+=	${PYPKGPREFIX}-py2app-[0-9]*:../../devel/py-py2app

RCD_SCRIPTS=		trytond
CONFDIR=		${PKG_SYSCONFDIR}/${PKGBASE}
EGDIR=			share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR} share/${PKGBASE}
MESSAGE_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

CONF_FILES+=		${EGDIR}/trytond.conf.example \
				${CONFDIR}/trytond.conf
CONF_FILES+=		${EGDIR}/logging.conf.example \
				${CONFDIR}/logging.conf

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/trytond-admin \
		${DESTDIR}${PREFIX}/bin/trytond-admin${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/trytond-cron \
		${DESTDIR}${PREFIX}/bin/trytond-cron${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/trytond \
		${DESTDIR}${PREFIX}/bin/trytond${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${FILESDIR}/trytond.conf.example \
		${DESTDIR}${PREFIX}/${EGDIR}/trytond.conf.example
	${INSTALL_DATA} ${FILESDIR}/logging.conf.example \
		${DESTDIR}${PREFIX}/${EGDIR}/logging.conf.example

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
