# $NetBSD: Makefile,v 1.10 2020/01/18 23:30:56 rillig Exp $
TRYTON_MODULE_NAME=	trytond_bank
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Bank module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-stdnum-[0-9]*:../../misc/py-stdnum
DEPENDS+=	${PYPKGPREFIX}-trytond-currency>=${TRYTON_BASEVER}:../../finance/py-trytond-currency
DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=		tests/test_bank.py
PYTHON_VERSIONS_ACCEPTED=	27 # py-simplesoap via py-stdnum

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
