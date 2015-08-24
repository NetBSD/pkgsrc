# $NetBSD: Makefile,v 1.1 2015/08/24 14:49:42 richard Exp $
TRYTON_MODULE_NAME=	trytond_analytic_purchase
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	The analytic purchase module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-account-[0-9]*:../../finance/py-trytond-analytic-account
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-invoice-[0-9]*:../../finance/py-trytond-analytic-invoice
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase-[0-9]*:../../finance/py-trytond-purchase
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_analytic_purchase.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
