# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:07 rillig Exp $
TRYTON_MODULE_NAME=	trytond_stock_location_sequence
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Tryton's stock location sequence module
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-python-sql>=0.4:../../databases/py-python-sql
#projrev
DEPENDS+=	${PYPKGPREFIX}-trytond-stock>=${TRYTON_BASEVER}:../../misc/py-trytond-stock
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
