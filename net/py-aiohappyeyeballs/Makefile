# $NetBSD: Makefile,v 1.12 2025/09/22 07:41:33 wiz Exp $

DISTNAME=	aiohappyeyeballs-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohappyeyeballs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohappyeyeballs
COMMENT=	Happy Eyeballs for Python
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.23.2:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=3.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
