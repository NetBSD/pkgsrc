# $NetBSD: Makefile,v 1.10 2023/11/10 19:08:11 adam Exp $

DISTNAME=	eth_abi-4.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-abi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-abi
COMMENT=	Python utilities for working with Ethereum ABI definitions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-eth-typing>=3.0.0:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-parsimonious>=0.9.0:../../textproc/py-parsimonious
TEST_DEPENDS+=	${PYPKGPREFIX}-eth-hash-[0-9]*:../../finance/py-eth-hash
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.18.2:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-pythonpath>=0.7.1:../../devel/py-test-pythonpath
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
