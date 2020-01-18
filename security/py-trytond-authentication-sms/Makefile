# $NetBSD: Makefile,v 1.3 2020/01/18 23:35:12 rillig Exp $
TRYTON_MODULE_NAME=	trytond_authentication_sms
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	python security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	The authentication_sms module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
