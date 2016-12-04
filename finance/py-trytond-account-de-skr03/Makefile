# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:00 rodent Exp $
TRYTON_MODULE_NAME=	trytond_account_de_skr03
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	The account_de_skr03 module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account>=${TRYTON_BASEVER}:../../finance/py-trytond-account
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
