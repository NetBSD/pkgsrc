# $NetBSD: Makefile,v 1.2 2016/12/04 21:13:06 rodent Exp $
TRYTON_MODULE_NAME=	trytond_party_relationship
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Party relationship module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_party_relationship.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
