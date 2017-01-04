# $NetBSD: Makefile,v 1.2 2017/01/04 23:45:28 rodent Exp $
TRYTON_MODULE_NAME=	trytond_party_vcarddav
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.tryton.org/
COMMENT=	Party vCard DAV module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.0:../../textproc/py-vobject
DEPENDS+=	${PYPKGPREFIX}-pywebdav>=0.9.8:../../www/py-pywebdav
DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
DEPENDS+=	${PYPKGPREFIX}-trytond-webdav>=${TRYTON_BASEVER}:../../www/py-trytond-webdav
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
