# $NetBSD: Makefile,v 1.17 2025/02/04 13:48:01 adam Exp $

DISTNAME=	eth_utils-5.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-utils/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-utils
COMMENT=	Common utility functions for ethereum codebases
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cytoolz>=0.10.1:../../devel/py-cytoolz
DEPENDS+=	${PYPKGPREFIX}-eth-hash>=0.3.1:../../finance/py-eth-hash
DEPENDS+=	${PYPKGPREFIX}-eth-typing>=5.0.0:../../finance/py-eth-typing
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.43.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.971:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
