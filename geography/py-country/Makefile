# $NetBSD: Makefile,v 1.8 2023/04/25 13:09:23 adam Exp $

DISTNAME=	pycountry-22.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycountry/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://bitbucket.org/flyingcircus/pycountry
COMMENT=	ISO country, subdivision, language, currency and script
LICENSE=	gnu-lgpl-v2.1

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC}/src/pycountry/tests && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
