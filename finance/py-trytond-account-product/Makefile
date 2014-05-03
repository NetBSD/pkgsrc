# $NetBSD: Makefile,v 1.3 2014/05/03 13:39:53 rodent Exp $

DISTNAME=	trytond_account_product-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/3.2/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Account product module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-product-[0-9]*:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-account-[0-9]*:../../finance/py-trytond-account
DEPENDS+=	${PYPKGPREFIX}-trytond-company-[0-9]*:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # XXX according to setup.py

REPLACE_PYTHON+=	tests/test_account_product.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
