# $NetBSD: Makefile,v 1.4 2022/01/04 20:54:19 wiz Exp $
TRYTON_MODULE_NAME=	trytond_carrier_weight
PKGREVISION= 1
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Carrier weight module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-carrier>=${TRYTON_BASEVER}:../../misc/py-trytond-carrier
DEPENDS+=	${PYPKGPREFIX}-trytond-company>=${TRYTON_BASEVER}:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-currency>=${TRYTON_BASEVER}:../../finance/py-trytond-currency
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-product-measurements>=${TRYTON_BASEVER}:../../misc/py-trytond-product-measurements
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
