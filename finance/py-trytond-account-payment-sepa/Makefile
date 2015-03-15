# $NetBSD: Makefile,v 1.3 2015/03/15 00:17:35 rodent Exp $
TRYTON_MODULE_NAME=	trytond_account_payment_sepa
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Account payment SEPA module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment-[0-9]*:../../finance/py-trytond-account-payment
DEPENDS+=	${PYPKGPREFIX}-trytond-bank-[0-9]*:../../finance/py-trytond-bank
DEPENDS+=	${PYPKGPREFIX}-trytond-company-[0-9]*:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-party-[0-9]*:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond
DEPENDS+=	${PYPKGPREFIX}-genshi-[0-9]*:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0:../../textproc/py-lxml

REPLACE_PYTHON+=	tests/test_account_payment_sepa.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
