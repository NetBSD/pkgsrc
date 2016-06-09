# $NetBSD: Makefile,v 1.3 2016/06/09 05:53:39 wiz Exp $

DISTNAME=	pycountry-1.10
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycountry/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/pycountry
COMMENT=	ISO country, subdivision, language, currency and script
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

do-test:
	${RUN} cd ${WRKSRC}/src/pycountry; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_general.py

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/pycountry/databases/*.xml
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/pycountry/locales/*/LC_MESSAGES/*.mo
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/pycountry/locales/*/LC_MESSAGES/*.po
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/pycountry/tests/test_general.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
