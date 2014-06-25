# $NetBSD: Makefile,v 1.5 2014/06/25 06:07:57 richard Exp $

.include "../../devel/py-trytond/Makefile.common"
DISTNAME=	trytond_product-${TRYTOND_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	misc python
MASTER_SITES=	${TRYTON_SITES}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Product module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_product.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
