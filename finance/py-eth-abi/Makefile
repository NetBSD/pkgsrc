# $NetBSD: Makefile,v 1.14 2025/02/04 13:50:24 adam Exp $

DISTNAME=	eth_abi-5.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-abi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-abi
COMMENT=	Python utilities for working with Ethereum ABI definitions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-eth-typing>=3.0.0:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-parsimonious>=0.10.0:../../textproc/py-parsimonious
TEST_DEPENDS+=	${PYPKGPREFIX}-eth-hash-[0-9]*:../../finance/py-eth-hash
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.22.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-pythonpath>=0.7.1:../../devel/py-test-pythonpath
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.0.0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
