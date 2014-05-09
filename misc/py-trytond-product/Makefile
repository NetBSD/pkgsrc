# $NetBSD: Makefile,v 1.4 2014/05/09 07:37:13 wiz Exp $

DISTNAME=	trytond_product-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	misc python
MASTER_SITES=	http://downloads.tryton.org/3.2/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Product module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	26 33 34 # XXX according to setup.py

REPLACE_PYTHON+=	tests/test_product.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
