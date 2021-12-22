# $NetBSD: Makefile,v 1.6 2021/12/22 22:54:52 mef Exp $
TRYTON_MODULE_NAME=	trytond_party_vcarddav
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	misc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Party vCard DAV module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.0:../../textproc/py-vobject
#EPENDS+=	${PYPKGPREFIX}-pywebdav>=0.9.8:../../www/py-pywebdav
DEPENDS+=	${PYPKGPREFIX}-python-sql-[0-9]*:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-trytond-party>=${TRYTON_BASEVER}:../../misc/py-trytond-party
#EPENDS+=	${PYPKGPREFIX}-trytond-webdav>=${TRYTON_BASEVER}:../../www/py-trytond-webdav
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

#YTHON_VERSIONS_ACCEPTED=	27 # py-pywebdav

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
