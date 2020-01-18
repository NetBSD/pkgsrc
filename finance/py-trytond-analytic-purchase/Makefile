# $NetBSD: Makefile,v 1.3 2020/01/18 23:30:56 rillig Exp $
TRYTON_MODULE_NAME=	trytond_analytic_purchase
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	The analytic purchase module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-account>=${TRYTON_BASEVER}:../../finance/py-trytond-analytic-account
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-invoice>=${TRYTON_BASEVER}:../../finance/py-trytond-analytic-invoice
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase>=${TRYTON_BASEVER}:../../finance/py-trytond-purchase
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_analytic_purchase.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
