# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:08 rodent Exp $
TRYTON_MODULE_NAME=	trytond_authentication_sms
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python security

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	The authentication_sms module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
