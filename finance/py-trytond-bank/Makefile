# $NetBSD: Makefile,v 1.5 2017/01/01 14:43:39 wiz Exp $
TRYTON_MODULE_NAME=	trytond_bank
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Bank module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=   ${PYPKGPREFIX}-stdnum-[0-9]*:../../misc/py-stdnum
DEPENDS+=   ${PYPKGPREFIX}-trytond-currency>=${TRYTON_BASEVER}:../../finance/py-trytond-currency
DEPENDS+=   ${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=   ${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_bank.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-simplesoap via py-stdnum

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
