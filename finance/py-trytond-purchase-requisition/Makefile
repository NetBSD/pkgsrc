# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:03 rodent Exp $
TRYTON_MODULE_NAME=	trytond_purchase_requisition
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Purchase requisition module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-company>=${TRYTON_BASEVER}:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-currency>=${TRYTON_BASEVER}:../../finance/py-trytond-currency
DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase>=${TRYTON_BASEVER}:../../finance/py-trytond-purchase
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase-request>=${TRYTON_BASEVER}:../../finance/py-trytond-purchase-request
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
