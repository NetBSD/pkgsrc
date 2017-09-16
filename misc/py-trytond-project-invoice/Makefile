# $NetBSD: Makefile,v 1.3 2017/09/16 19:27:02 wiz Exp $
TRYTON_MODULE_NAME=	trytond_project_invoice
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Project invoice module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql>=0.4:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-project>=${TRYTON_BASEVER}:../../misc/py-trytond-project
DEPENDS+=	${PYPKGPREFIX}-trytond-project-revenue>=${TRYTON_BASEVER}:../../misc/py-trytond-project-revenue
DEPENDS+=	${PYPKGPREFIX}-trytond-timesheet>=${TRYTON_BASEVER}:../../time/py-trytond-timesheet
DEPENDS+=	${PYPKGPREFIX}-trytond-account>=${TRYTON_BASEVER}:../../finance/py-trytond-account
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice>=${TRYTON_BASEVER}:../../finance/py-trytond-account-invoice
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
