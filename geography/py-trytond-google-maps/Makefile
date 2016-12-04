# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:05 rodent Exp $
TRYTON_MODULE_NAME=	trytond_google_maps
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	geography python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Google Maps module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

PY_PATCHPLIST=			yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
