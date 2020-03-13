# $NetBSD: Makefile,v 1.10 2020/03/13 20:20:49 wiz Exp $
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

PYTHON_VERSIONS_ACCEPTED=	27 # some dependencies only for python-2.7 as of 20200313

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-trytond-ldap-authentication>=${TRYTON_BASEVER}:../../databases/py-trytond-ldap-authentication
DEPENDS+=	${PYPKGPREFIX}-tryton>=${TRYTON_BASEVER}:../../devel/py-tryton
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond
DEPENDS+=	${PYPKGPREFIX}-trytond-account>=${TRYTON_BASEVER}:../../finance/py-trytond-account
DEPENDS+=	${PYPKGPREFIX}-trytond-account-asset>=${TRYTON_BASEVER}:../../finance/py-trytond-account-asset
DEPENDS+=	${PYPKGPREFIX}-trytond-account-be>=${TRYTON_BASEVER}:../../finance/py-trytond-account-be
DEPENDS+=	${PYPKGPREFIX}-trytond-account-credit-limit>=${TRYTON_BASEVER}:../../finance/py-trytond-account-credit-limit
DEPENDS+=	${PYPKGPREFIX}-trytond-account-de-skr03>=${TRYTON_BASEVER}:../../finance/py-trytond-account-de-skr03
DEPENDS+=	${PYPKGPREFIX}-trytond-account-deposit>=${TRYTON_BASEVER}:../../finance/py-trytond-account-deposit
DEPENDS+=	${PYPKGPREFIX}-trytond-account-dunning>=${TRYTON_BASEVER}:../../finance/py-trytond-account-dunning
DEPENDS+=	${PYPKGPREFIX}-trytond-account-dunning-fee>=${TRYTON_BASEVER}:../../finance/py-trytond-account-dunning-fee
DEPENDS+=	${PYPKGPREFIX}-trytond-account-dunning-letter>=${TRYTON_BASEVER}:../../finance/py-trytond-account-dunning-letter
DEPENDS+=	${PYPKGPREFIX}-trytond-account-fr>=${TRYTON_BASEVER}:../../finance/py-trytond-account-fr
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice>=${TRYTON_BASEVER}:../../finance/py-trytond-account-invoice
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice-history>=${TRYTON_BASEVER}:../../finance/py-trytond-account-invoice-history
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice-line-standalone>=${TRYTON_BASEVER}:../../finance/py-trytond-account-invoice-line-standalone
DEPENDS+=	${PYPKGPREFIX}-trytond-account-invoice-stock>=${TRYTON_BASEVER}:../../finance/py-trytond-account-invoice-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment>=${TRYTON_BASEVER}:../../finance/py-trytond-account-payment
DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment-clearing>=${TRYTON_BASEVER}:../../finance/py-trytond-account-payment-clearing
DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment-sepa>=${TRYTON_BASEVER}:../../finance/py-trytond-account-payment-sepa
DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment-sepa-cfonb>=${TRYTON_BASEVER}:../../finance/py-trytond-account-payment-sepa-cfonb
DEPENDS+=	${PYPKGPREFIX}-trytond-account-product>=${TRYTON_BASEVER}:../../finance/py-trytond-account-product
DEPENDS+=	${PYPKGPREFIX}-trytond-account-statement>=${TRYTON_BASEVER}:../../finance/py-trytond-account-statement
DEPENDS+=	${PYPKGPREFIX}-trytond-account-stock-anglo-saxon>=${TRYTON_BASEVER}:../../finance/py-trytond-account-stock-anglo-saxon
DEPENDS+=	${PYPKGPREFIX}-trytond-account-stock-continental>=${TRYTON_BASEVER}:../../finance/py-trytond-account-stock-continental
DEPENDS+=	${PYPKGPREFIX}-trytond-account-stock-landed-cost>=${TRYTON_BASEVER}:../../finance/py-trytond-account-stock-landed-cost
DEPENDS+=	${PYPKGPREFIX}-trytond-account-stock-landed-cost-weight>=${TRYTON_BASEVER}:../../finance/py-trytond-account-stock-landed-cost-weight
DEPENDS+=	${PYPKGPREFIX}-trytond-account-tax-rule-country>=${TRYTON_BASEVER}:../../finance/py-trytond-account-tax-rule-country
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-account>=${TRYTON_BASEVER}:../../finance/py-trytond-analytic-account
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-invoice>=${TRYTON_BASEVER}:../../finance/py-trytond-analytic-invoice
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-purchase>=${TRYTON_BASEVER}:../../finance/py-trytond-analytic-purchase
DEPENDS+=	${PYPKGPREFIX}-trytond-analytic-sale>=${TRYTON_BASEVER}:../../finance/py-trytond-analytic-sale
DEPENDS+=	${PYPKGPREFIX}-trytond-bank>=${TRYTON_BASEVER}:../../finance/py-trytond-bank
DEPENDS+=	${PYPKGPREFIX}-trytond-carrier-percentage>=${TRYTON_BASEVER}:../../misc/py-trytond-carrier-percentage
DEPENDS+=	${PYPKGPREFIX}-trytond-carrier-weight>=${TRYTON_BASEVER}:../../misc/py-trytond-carrier-weight
DEPENDS+=	${PYPKGPREFIX}-trytond-carrier>=${TRYTON_BASEVER}:../../misc/py-trytond-carrier
DEPENDS+=	${PYPKGPREFIX}-trytond-commission-waiting>=${TRYTON_BASEVER}:../../finance/py-trytond-commission-waiting
DEPENDS+=	${PYPKGPREFIX}-trytond-commission>=${TRYTON_BASEVER}:../../finance/py-trytond-commission
DEPENDS+=	${PYPKGPREFIX}-trytond-currency>=${TRYTON_BASEVER}:../../finance/py-trytond-currency
DEPENDS+=	${PYPKGPREFIX}-trytond-customs>=${TRYTON_BASEVER}:../../finance/py-trytond-customs
DEPENDS+=	${PYPKGPREFIX}-trytond-product-cost-fifo>=${TRYTON_BASEVER}:../../finance/py-trytond-product-cost-fifo
DEPENDS+=	${PYPKGPREFIX}-trytond-product-cost-history>=${TRYTON_BASEVER}:../../finance/py-trytond-product-cost-history
DEPENDS+=	${PYPKGPREFIX}-trytond-product-measurements>=${TRYTON_BASEVER}:../../misc/py-trytond-product-measurements
DEPENDS+=	${PYPKGPREFIX}-trytond-product-price-list>=${TRYTON_BASEVER}:../../finance/py-trytond-product-price-list
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase>=${TRYTON_BASEVER}:../../finance/py-trytond-purchase
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase-request>=${TRYTON_BASEVER}:../../finance/py-trytond-purchase-request
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase-requisition>=${TRYTON_BASEVER}:../../finance/py-trytond-purchase-requisition
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase-shipment-cost>=${TRYTON_BASEVER}:../../finance/py-trytond-purchase-shipment-cost
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase-invoice-line-standalone>=${TRYTON_BASEVER}:../../finance/py-trytond-purchase-invoice-line-standalone
DEPENDS+=	${PYPKGPREFIX}-trytond-sale>=${TRYTON_BASEVER}:../../finance/py-trytond-sale
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-complaint>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-complaint
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-credit-limit>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-credit-limit
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-extra>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-extra
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-invoice-grouping>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-invoice-grouping
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-opportunity>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-opportunity
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-price-list>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-price-list
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-promotion>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-promotion
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-shipment-cost>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-shipment-cost
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-shipment-grouping>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-shipment-grouping
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-stock-quantity>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-stock-quantity
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-supply>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-supply
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-supply-drop-shipment>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-supply-drop-shipment
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-supply>=${TRYTON_BASEVER}:../../finance/py-trytond-stock-supply
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-supply-day>=${TRYTON_BASEVER}:../../finance/py-trytond-stock-supply-day
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-supply-forecast>=${TRYTON_BASEVER}:../../finance/py-trytond-stock-supply-forecast
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-supply-production>=${TRYTON_BASEVER}:../../finance/py-trytond-stock-supply-production
DEPENDS+=	${PYPKGPREFIX}-trytond-country>=${TRYTON_BASEVER}:../../geography/py-trytond-country
DEPENDS+=	${PYPKGPREFIX}-trytond-google-maps>=${TRYTON_BASEVER}:../../geography/py-trytond-google-maps
DEPENDS+=	${PYPKGPREFIX}-trytond-company>=${TRYTON_BASEVER}:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-dashboard>=${TRYTON_BASEVER}:../../misc/py-trytond-dashboard
DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-party-relationship>=${TRYTON_BASEVER}:../../misc/py-trytond-party-relationship
DEPENDS+=	${PYPKGPREFIX}-trytond-party-siret>=${TRYTON_BASEVER}:../../misc/py-trytond-party-siret
DEPENDS+=	${PYPKGPREFIX}-trytond-party-vcarddav>=${TRYTON_BASEVER}:../../misc/py-trytond-party-vcarddav
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-production-routing>=${TRYTON_BASEVER}:../../misc/py-trytond-production-routing
DEPENDS+=	${PYPKGPREFIX}-trytond-production-split>=${TRYTON_BASEVER}:../../misc/py-trytond-production-split
DEPENDS+=	${PYPKGPREFIX}-trytond-production-work-timesheet>=${TRYTON_BASEVER}:../../misc/py-trytond-production-work-timesheet
DEPENDS+=	${PYPKGPREFIX}-trytond-production-work>=${TRYTON_BASEVER}:../../misc/py-trytond-production-work
DEPENDS+=	${PYPKGPREFIX}-trytond-production>=${TRYTON_BASEVER}:../../misc/py-trytond-production
DEPENDS+=	${PYPKGPREFIX}-trytond-product-attribute>=${TRYTON_BASEVER}:../../misc/py-trytond-product-attribute
DEPENDS+=	${PYPKGPREFIX}-trytond-product-classification-taxonomic>=${TRYTON_BASEVER}:../../misc/py-trytond-product-classification-taxonomic
DEPENDS+=	${PYPKGPREFIX}-trytond-product-classification>=${TRYTON_BASEVER}:../../misc/py-trytond-product-classification
DEPENDS+=	${PYPKGPREFIX}-trytond-project-invoice>=${TRYTON_BASEVER}:../../misc/py-trytond-project-invoice
DEPENDS+=	${PYPKGPREFIX}-trytond-project-plan>=${TRYTON_BASEVER}:../../misc/py-trytond-project-plan
DEPENDS+=	${PYPKGPREFIX}-trytond-project-revenue>=${TRYTON_BASEVER}:../../misc/py-trytond-project-revenue
DEPENDS+=	${PYPKGPREFIX}-trytond-project>=${TRYTON_BASEVER}:../../misc/py-trytond-project
DEPENDS+=	${PYPKGPREFIX}-trytond-stock>=${TRYTON_BASEVER}:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-forecast>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-forecast
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-inventory-location>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-inventory-location
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-location-sequence>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-location-sequence
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-lot>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-lot
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-lot-sled>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-lot-sled
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-package>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-package
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-package-shipping>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-package-shipping
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-package-shipping-dpd>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-package-shipping-dpd
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-package-shipping-ups>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-package-shipping-ups
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-product-location>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-product-location
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-split>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-split
DEPENDS+=	${PYPKGPREFIX}-trytond-authentication-sms>=${TRYTON_BASEVER}:../../security/py-trytond-authentication-sms
DEPENDS+=	${PYPKGPREFIX}-trytond-calendar-classification>=${TRYTON_BASEVER}:../../time/py-trytond-calendar-classification
DEPENDS+=	${PYPKGPREFIX}-trytond-calendar-scheduling>=${TRYTON_BASEVER}:../../time/py-trytond-calendar-scheduling
DEPENDS+=	${PYPKGPREFIX}-trytond-calendar-todo>=${TRYTON_BASEVER}:../../time/py-trytond-calendar-todo
DEPENDS+=	${PYPKGPREFIX}-trytond-calendar>=${TRYTON_BASEVER}:../../time/py-trytond-calendar
DEPENDS+=	${PYPKGPREFIX}-trytond-company-work-time>=${TRYTON_BASEVER}:../../time/py-trytond-company-work-time
DEPENDS+=	${PYPKGPREFIX}-trytond-timesheet-cost>=${TRYTON_BASEVER}:../../time/py-trytond-timesheet-cost
DEPENDS+=	${PYPKGPREFIX}-trytond-timesheet>=${TRYTON_BASEVER}:../../time/py-trytond-timesheet
DEPENDS+=	${PYPKGPREFIX}-trytond-web-user>=${TRYTON_BASEVER}:../../www/py-trytond-web-user
DEPENDS+=	${PYPKGPREFIX}-trytond-webdav>=${TRYTON_BASEVER}:../../www/py-trytond-webdav

PYTHON_VERSIONS_ACCEPTED=	27 # py-simplesoap via py-stdnum and py-trytond-bank

.include "../../mk/bsd.pkg.mk"
