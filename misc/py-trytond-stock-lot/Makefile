# $NetBSD: Makefile,v 1.4 2014/05/09 07:37:13 wiz Exp $

DISTNAME=	trytond_stock_lot-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	misc python
MASTER_SITES=	http://downloads.tryton.org/3.2/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Stock lot module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-stock-[0-9]*:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond-product-[0-9]*:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_stock_lot.py
PYTHON_VERSIONS_INCOMPATIBLE=	26 33 34 # XXX according to setup.py (v3.0.0)

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
