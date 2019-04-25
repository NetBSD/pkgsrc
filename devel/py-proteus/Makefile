# $NetBSD: Makefile,v 1.5 2019/04/25 07:32:49 maya Exp $
TRYTON_MODULE_NAME=	proteus
PKGREVISION= 1
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Library to access Tryton's models like a client
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "options.mk"

REPLACE_PYTHON+=	tests/test_wizard.py tests/test_report.py tests/test_model.py tests/test_context.py
REPLACE_PYTHON+=	tests/test_config.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
