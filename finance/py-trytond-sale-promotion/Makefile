# $NetBSD: Makefile,v 1.2 2017/01/04 23:45:28 rodent Exp $
TRYTON_MODULE_NAME=	trytond_sale_promotion
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Sale promotion module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-simpleeval-[0-9]*:../../math/py-simpleeval
DEPENDS+=	${PYPKGPREFIX}-trytond-company>=${TRYTON_BASEVER}:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-product-price-list>=${TRYTON_BASEVER}:../../finance/py-trytond-product-price-list
DEPENDS+=	${PYPKGPREFIX}-trytond-sale>=${TRYTON_BASEVER}:../../finance/py-trytond-sale
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-price-list>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-price-list
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
