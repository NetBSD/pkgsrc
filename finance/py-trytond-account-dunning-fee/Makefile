# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:00 rodent Exp $
TRYTON_MODULE_NAME=	trytond_account_dunning_fee
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Tryton's account_dunning_fee module
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account-dunning>=${TRYTON_BASEVER}:../../finance/py-trytond-account-dunning
DEPENDS+=	${PYPKGPREFIX}-trytond-account-product>=${TRYTON_BASEVER}:../../finance/py-trytond-account-product
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
