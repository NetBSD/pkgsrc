# $NetBSD: Makefile,v 1.1 2015/08/24 14:49:43 richard Exp $
TRYTON_MODULE_NAME=	trytond_product_cost_history
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	The product cost history module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-product-[0-9]*:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_product_cost_history.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
