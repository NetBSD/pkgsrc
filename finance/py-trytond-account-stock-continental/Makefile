# $NetBSD: Makefile,v 1.1 2015/08/24 14:49:42 richard Exp $
TRYTON_MODULE_NAME=	trytond_account_stock_continental
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Account stock continental module of the Tryton platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account-[0-9]*:../../finance/py-trytond-account
DEPENDS+=	${PYPKGPREFIX}-trytond-account-product-[0-9]*:../../finance/py-trytond-account-product
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-[0-9]*:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_account_stock_continental.py tests/tools.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
