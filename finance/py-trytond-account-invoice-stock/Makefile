# $NetBSD: Makefile,v 1.3 2020/01/18 23:30:54 rillig Exp $
TRYTON_MODULE_NAME=	trytond_account_invoice_stock
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Account invoice stock module of the Tryton platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-stock>=${TRYTON_BASEVER}:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice>=${TRYTON_BASEVER}:../../finance/py-trytond-account-invoice
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_account_invoice_stock.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
