# $NetBSD: Makefile,v 1.2 2015/08/24 15:50:08 richard Exp $
#
DISTNAME=	# empty
PKGNAME=	${PYPKGPREFIX}-tryton-platform-${TRYTON_BASEVER}
.include "../../devel/py-trytond/Makefile.common"

CATEGORIES=	meta-pkgs python
MASTER_SITES=	# empty
DISTFILES=	# empty
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Install complete tryton client/server platform

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-tryton-[0-9]*:../../devel/py-tryton
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond
DEPENDS+=	${PYPKGPREFIX}-trytond-account-[0-9]*:../../finance/py-trytond-account
DEPENDS+=	${PYPKGPREFIX}-trytond-account-asset-[0-9]*:../../finance/py-trytond-account-asset
DEPENDS+=	${PYPKGPREFIX}-trytond-account-fr-[0-9]*:../../finance/py-trytond-account-fr
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice-[0-9]*:../../finance/py-trytond-account-invoice
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice-history-[0-9]*:../../finance/py-trytond-account-invoice-history
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice-line-standalone-[0-9]*:../../finance/py-trytond-account-invoice-line-standalone
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice-stock-[0-9]*:../../finance/py-trytond-account-invoice-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment-[0-9]*:../../finance/py-trytond-account-payment
DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment-clearing-[0-9]*:../../finance/py-trytond-account-payment-clearing
DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment-sepa-[0-9]*:../../finance/py-trytond-account-payment-sepa
DEPENDS+=	${PYPKGPREFIX}-trytond-account-product-[0-9]*:../../finance/py-trytond-account-product
DEPENDS+=	${PYPKGPREFIX}-trytond-account-statement-[0-9]*:../../finance/py-trytond-account-statement
DEPENDS+=	${PYPKGPREFIX}-trytond-account-stock-continental-[0-9]*:../../finance/py-trytond-account-stock-continental
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-account-[0-9]*:../../finance/py-trytond-analytic-account
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-invoice-[0-9]*:../../finance/py-trytond-analytic-invoice
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-purchase-[0-9]*:../../finance/py-trytond-analytic-purchase
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-sale-[0-9]*:../../finance/py-trytond-analytic-sale
DEPENDS+=	${PYPKGPREFIX}-trytond-bank-[0-9]*:../../finance/py-trytond-bank
DEPENDS+=	${PYPKGPREFIX}-trytond-currency-[0-9]*:../../finance/py-trytond-currency
DEPENDS+=	${PYPKGPREFIX}-trytond-product-cost-fifo-[0-9]*:../../finance/py-trytond-product-cost-fifo
DEPENDS+=	${PYPKGPREFIX}-trytond-product-cost-history-[0-9]*:../../finance/py-trytond-product-cost-history
DEPENDS+=	${PYPKGPREFIX}-trytond-product-price-list-[0-9]*:../../finance/py-trytond-product-price-list
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase-[0-9]*:../../finance/py-trytond-purchase
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase-invoice-line-standalone-[0-9]*:../../finance/py-trytond-purchase-invoice-line-standalone
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-[0-9]*:../../finance/py-trytond-sale
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-supply-[0-9]*:../../finance/py-trytond-stock-supply
DEPENDS+=	${PYPKGPREFIX}-trytond-country-[0-9]*:../../geography/py-trytond-country
DEPENDS+=	${PYPKGPREFIX}-trytond-company-[0-9]*:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-party-[0-9]*:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-party-relationship-[0-9]*:../../misc/py-trytond-party-relationship
DEPENDS+=	${PYPKGPREFIX}-trytond-party-siret-[0-9]*:../../misc/py-trytond-party-siret
DEPENDS+=	${PYPKGPREFIX}-trytond-product-[0-9]*:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-production-[0-9]*:../../misc/py-trytond-production
DEPENDS+=	${PYPKGPREFIX}-trytond-product-attribute-[0-9]*:../../misc/py-trytond-product-attribute
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-[0-9]*:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-inventory-location-[0-9]*:../../misc/py-trytond-stock-inventory-location
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-lot-[0-9]*:../../misc/py-trytond-stock-lot
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-product-location-[0-9]*:../../misc/py-trytond-stock-product-location
DEPENDS+=	${PYPKGPREFIX}-trytond-calendar-[0-9]*:../../time/py-trytond-calendar
DEPENDS+=	${PYPKGPREFIX}-trytond-company-work-time-[0-9]*:../../time/py-trytond-company-work-time

.include "../../mk/bsd.pkg.mk"
