# $NetBSD: Makefile,v 1.4 2022/01/04 20:53:56 wiz Exp $
TRYTON_MODULE_NAME=	trytond_account_payment_clearing
PKGREVISION= 1
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Account payment clearing module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account-payment>=${TRYTON_BASEVER}:../../finance/py-trytond-account-payment
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

REPLACE_PYTHON+=	tests/test_account_payment_clearing.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
