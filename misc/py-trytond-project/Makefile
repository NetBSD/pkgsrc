# $NetBSD: Makefile,v 1.2 2017/01/04 23:45:29 rodent Exp $
TRYTON_MODULE_NAME=	trytond_project
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Project module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql>=0.4:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-company-work-time>=${TRYTON_BASEVER}:../../time/py-trytond-company-work-time
DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-timesheet>=${TRYTON_BASEVER}:../../time/py-trytond-timesheet
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
