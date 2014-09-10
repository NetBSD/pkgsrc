# $NetBSD: Makefile,v 1.1 2014/09/10 16:03:48 richard Exp $
TRYTOND_MODULE_REVISION=	1
.include "../../devel/py-trytond/Makefile.common"
DISTNAME=	trytond_analytic_account-${TRYTOND_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	finance python
MASTER_SITES=	${TRYTON_SITES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	The analytic_account module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account-[0-9]*:../../finance/py-trytond-account
DEPENDS+=	${PYPKGPREFIX}-trytond-company-[0-9]*:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-party-[0-9]*:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-currency-[0-9]*:../../finance/py-trytond-currency
DEPENDS+=	${PYPKGPREFIX}-trytond-[0-9]*:../../devel/py-trytond

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

REPLACE_PYTHON+=	tests/test_analytic_account.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
