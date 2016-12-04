# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:04 rodent Exp $
TRYTON_MODULE_NAME=	trytond_stock_supply_production
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Tryton's stock supply production module
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-production>=${TRYTON_BASEVER}:../../misc/py-trytond-production
DEPENDS+=	${PYPKGPREFIX}-trytond-stock>=${TRYTON_BASEVER}:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-supply>=${TRYTON_BASEVER}:../../finance/py-trytond-stock-supply
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
