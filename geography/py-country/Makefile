# $NetBSD: Makefile,v 1.5 2019/05/31 12:37:04 adam Exp $

DISTNAME=	pycountry-18.12.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycountry/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://bitbucket.org/flyingcircus/pycountry
COMMENT=	ISO country, subdivision, language, currency and script
LICENSE=	gnu-lgpl-v2.1

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/src/pycountry/tests && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
