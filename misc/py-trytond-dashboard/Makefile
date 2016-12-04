# $NetBSD: Makefile,v 1.1 2016/12/04 21:13:05 rodent Exp $
TRYTON_MODULE_NAME=	trytond_dashboard
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Dashboard module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-python-sql>=0.4:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
