# $NetBSD: Makefile,v 1.12 2022/01/04 20:54:20 wiz Exp $
TRYTON_MODULE_NAME=	trytond_party
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Party module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-country>=${TRYTON_BASEVER}:../../geography/py-trytond-country
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_party.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
