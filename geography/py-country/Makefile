# $NetBSD: Makefile,v 1.1 2017/08/27 12:27:13 adam Exp $

DISTNAME=	pycountry-17.5.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycountry/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/pycountry
COMMENT=	ISO country, subdivision, language, currency and script
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		# none

do-test:
	cd ${WRKSRC}/src/pycountry/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_general.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
