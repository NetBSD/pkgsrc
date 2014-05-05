# $NetBSD: Makefile,v 1.3 2014/05/05 22:58:41 joerg Exp $

DISTNAME=	trytond_company-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	misc python
MASTER_SITES=	http://downloads.tryton.org/3.2/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Company module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-party-[0-9]*:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-currency-[0-9]*:../../finance/py-trytond-currency
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_company.py
PYTHON_VERSIONS_INCOMPATIBLE=	26 33 # XXX according to setup.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
