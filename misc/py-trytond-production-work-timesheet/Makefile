# $NetBSD: Makefile,v 1.4 2022/01/04 20:54:21 wiz Exp $
TRYTON_MODULE_NAME=	trytond_production_work_timesheet
PKGREVISION= 1
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
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
