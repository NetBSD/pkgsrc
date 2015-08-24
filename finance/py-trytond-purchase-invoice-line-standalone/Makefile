# $NetBSD: Makefile,v 1.1 2015/08/24 14:49:43 richard Exp $
TRYTON_MODULE_NAME=	trytond_purchase_invoice_line_standalone
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Purchase invoice line standalone module of the Tryton platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice-line-standalone-[0-9]*:../../finance/py-trytond-account-invoice-line-standalone
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase-[0-9]*:../../finance/py-trytond-purchase
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_purchase_invoice_line_standalone.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
