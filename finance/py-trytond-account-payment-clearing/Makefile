# $NetBSD: Makefile,v 1.1 2015/08/24 14:49:42 richard Exp $
TRYTON_MODULE_NAME=	trytond_account_payment_clearing
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Account payment clearing module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment-[0-9]*:../../finance/py-trytond-account-payment
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

REPLACE_PYTHON+=	tests/test_account_payment_clearing.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
