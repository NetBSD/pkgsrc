# $NetBSD: Makefile,v 1.1 2014/02/01 18:10:53 rodent Exp $

DISTNAME=	trytond_country-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	geography python
MASTER_SITES=	http://downloads.tryton.org/3.0/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Country module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_country.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
