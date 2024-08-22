# $NetBSD: Makefile,v 1.5 2024/08/22 12:00:35 adam Exp $

DISTNAME=	aiohappyeyeballs-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohappyeyeballs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohappyeyeballs
COMMENT=	Happy Eyeballs for Python
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.23.2:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=3.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
