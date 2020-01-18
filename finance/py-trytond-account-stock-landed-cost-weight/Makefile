# $NetBSD: Makefile,v 1.4 2020/01/18 23:30:55 rillig Exp $
TRYTON_MODULE_NAME=	trytond_account_stock_landed_cost_weight
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Tryton's account stock landed cost weight module
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account-stock-landed-cost>=${TRYTON_BASEVER}:../../finance/py-trytond-account-stock-landed-cost
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-product-measurements>=${TRYTON_BASEVER}:../../misc/py-trytond-product-measurements
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
