# $NetBSD: Makefile,v 1.11 2024/10/11 13:43:48 adam Exp $

DISTNAME=	pycountry-24.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	geography python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycountry/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/pycountry/pycountry
COMMENT=	ISO country, subdivision, language, currency and script
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
