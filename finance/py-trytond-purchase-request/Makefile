# $NetBSD: Makefile,v 1.2 2017/01/04 23:45:27 rodent Exp $
TRYTON_MODULE_NAME=	trytond_purchase_request
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Purchase request module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-purchase>=${TRYTON_BASEVER}:../../finance/py-trytond-purchase
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_purchase_request.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
