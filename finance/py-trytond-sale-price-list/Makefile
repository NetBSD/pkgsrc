# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:04 rodent Exp $
TRYTON_MODULE_NAME=	trytond_sale_price_list
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Sale price list module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-product-price-list>=${TRYTON_BASEVER}:../../finance/py-trytond-product-price-list
DEPENDS+=	${PYPKGPREFIX}-trytond-sale>=${TRYTON_BASEVER}:../../finance/py-trytond-sale
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
