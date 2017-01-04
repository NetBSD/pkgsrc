# $NetBSD: Makefile,v 1.2 2017/01/04 23:45:28 rodent Exp $
TRYTON_MODULE_NAME=	trytond_stock_supply_forecast
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Stock supply forecast module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-stock-supply>=${TRYTON_BASEVER}:../../finance/py-trytond-stock-supply
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-forecast>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-forecast
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
