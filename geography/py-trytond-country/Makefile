# $NetBSD: Makefile,v 1.14 2022/01/05 15:41:11 wiz Exp $
TRYTON_MODULE_NAME=	trytond_country
PKGREVISION= 2
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	geography python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Country module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	tests/test_country.py

USE_PKG_RESOURCES=	yes

PY_PATCHPLIST=			yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/trytond_import_zip \
		${DESTDIR}${PREFIX}/bin/trytond${PYVERSSUFFIX}_import_zip || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
