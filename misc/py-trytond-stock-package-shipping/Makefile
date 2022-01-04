# $NetBSD: Makefile,v 1.4 2022/01/04 20:54:22 wiz Exp $
TRYTON_MODULE_NAME=	trytond_stock_package_shipping
PKGREVISION= 1
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Stock package shipping module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-carrier>=${TRYTON_BASEVER}:../../misc/py-trytond-carrier
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-stock>=${TRYTON_BASEVER}:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-package>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-package
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-shipment-cost>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-shipment-cost
DEPENDS+=	${PYPKGPREFIX}-trytond-product-measurements>=${TRYTON_BASEVER}:../../misc/py-trytond-product-measurements
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
