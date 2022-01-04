# $NetBSD: Makefile,v 1.4 2022/01/04 20:54:23 wiz Exp $
TRYTON_MODULE_NAME=	trytond_stock_package_shipping_ups
PKGREVISION= 1
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Tryton's stock package shipping UPS module
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-stock>=${TRYTON_BASEVER}:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-package>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-package
DEPENDS+=	${PYPKGPREFIX}-trytond-stock-package-shipping>=${TRYTON_BASEVER}:../../misc/py-trytond-stock-package-shipping
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
