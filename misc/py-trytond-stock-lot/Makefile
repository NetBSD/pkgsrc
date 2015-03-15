# $NetBSD: Makefile,v 1.6 2015/03/15 00:17:36 rodent Exp $
TRYTON_MODULE_NAME=	trytond_stock_lot
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Stock lot module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-stock-[0-9]*:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-product-[0-9]*:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_stock_lot.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
