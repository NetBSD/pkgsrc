# $NetBSD: Makefile,v 1.3 2015/08/24 14:49:42 richard Exp $
TRYTON_MODULE_NAME=	trytond_account_payment
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Account_payment module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-currency-[0-9]*:../../finance/py-trytond-currency
DEPENDS+=	${PYPKGPREFIX}-trytond-account-[0-9]*:../../finance/py-trytond-account
DEPENDS+=	${PYPKGPREFIX}-trytond-company-[0-9]*:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-party-[0-9]*:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_account_payment.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
