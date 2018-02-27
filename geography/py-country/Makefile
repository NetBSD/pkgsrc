# $NetBSD: Makefile,v 1.3 2018/02/27 13:08:03 adam Exp $

DISTNAME=	pycountry-18.2.23
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycountry/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/pycountry
COMMENT=	ISO country, subdivision, language, currency and script
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/src/pycountry/tests && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
