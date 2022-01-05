# $NetBSD: Makefile,v 1.27 2022/01/05 15:41:08 wiz Exp $
TRYTON_MODULE_NAME=	trytond
PKGREVISION= 2
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=     devel python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Tryton server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-lxml>=2.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-relatorio>=0.7.0:../../textproc/py-relatorio
DEPENDS+=	${PYPKGPREFIX}-genshi-[0-9]*:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
DEPENDS+=	${PYPKGPREFIX}-python-sql>=0.5:../../databases/py-python-sql
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-wrapt-[0-9]*:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7.0:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic
TEST_DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

USE_PKG_RESOURCES=	yes

post-install:
.for f in trytond trytond-admin trytond-console trytond-cron trytond-stat trytond-worker
	${MV} ${DESTDIR}${PREFIX}/bin/${f} \
		${DESTDIR}${PREFIX}/bin/${f}${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
