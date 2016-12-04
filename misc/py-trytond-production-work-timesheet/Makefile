# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:07 rodent Exp $
TRYTON_MODULE_NAME=	trytond_production_work_timesheet
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Tryton's production work timesheet module
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-production-routing>=${TRYTON_BASEVER}:../../misc/py-trytond-production-routing
DEPENDS+=	${PYPKGPREFIX}-trytond-production-work>=${TRYTON_BASEVER}:../../misc/py-trytond-production-work
DEPENDS+=	${PYPKGPREFIX}-trytond-timesheet>=${TRYTON_BASEVER}:../../time/py-trytond-timesheet
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
