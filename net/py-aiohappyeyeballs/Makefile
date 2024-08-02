# $NetBSD: Makefile,v 1.2 2024/08/02 07:32:16 adam Exp $

DISTNAME=	aiohappyeyeballs-2.3.4
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
