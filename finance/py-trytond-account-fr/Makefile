# $NetBSD: Makefile,v 1.5 2016/12/04 21:13:00 rodent Exp $
TRYTON_MODULE_NAME=	trytond_account_fr
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	The account_fr module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account>=${TRYTON_BASEVER}:../../finance/py-trytond-account
DEPENDS+=	${PYPKGPREFIX}-trytond-party-siret>=${TRYTON_BASEVER}:../../misc/py-trytond-party-siret
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_account_fr.py tests/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
