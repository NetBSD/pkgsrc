# $NetBSD: Makefile,v 1.1 2014/05/15 05:35:27 richard Exp $

DISTNAME=	trytond_party_siret-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/1}
CATEGORIES=	misc python
MASTER_SITES=	http://downloads.tryton.org/3.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	The party_siret module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-party-[0-9]*:../../misc/py-trytond-party

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_party_siret.py
PYTHON_VERSIONS_INCOMPATIBLE=	26 33 34 # XXX according to setup.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
