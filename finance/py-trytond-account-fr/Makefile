# $NetBSD: Makefile,v 1.1 2014/05/15 05:33:45 richard Exp $

DISTNAME=	trytond_account_fr-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	finance python
MASTER_SITES=	http://downloads.tryton.org/3.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	The account_fr module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-account-[0-9]*:../../finance/py-trytond-account

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	26 33 34 # XXX according to setup.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
