# $NetBSD: Makefile,v 1.3 2017/09/16 19:26:56 wiz Exp $
TRYTON_MODULE_NAME=	trytond_stock_supply_forecast
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
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
