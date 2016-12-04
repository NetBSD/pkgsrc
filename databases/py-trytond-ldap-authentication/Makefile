# $NetBSD: Makefile,v 1.1 2016/12/04 21:12:59 rodent Exp $
TRYTON_MODULE_NAME=	trytond_ldap_authentication
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	databases python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	LDAP authentication module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-ldap3-[0-9]*:../../databases/py-ldap3
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
