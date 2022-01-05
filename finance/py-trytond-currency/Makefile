# $NetBSD: Makefile,v 1.13 2022/01/05 15:41:10 wiz Exp $ 
TRYTON_MODULE_NAME=	trytond_currency
PKGREVISION= 2
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Currency module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

REPLACE_PYTHON+=	tests/test_currency.py tests/tools.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
