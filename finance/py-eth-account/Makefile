# $NetBSD: Makefile,v 1.13 2024/02/09 06:20:31 adam Exp $

DISTNAME=	eth-account-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-account/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-account
COMMENT=	Sign Ethereum transactions and messages with local private keys
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-bitarray>=2.4.0:../../devel/py-bitarray
DEPENDS+=	${PYPKGPREFIX}-eth-abi>=4.0.0:../../finance/py-eth-abi
DEPENDS+=	${PYPKGPREFIX}-eth-keyfile>=0.6.0:../../finance/py-eth-keyfile
DEPENDS+=	${PYPKGPREFIX}-eth-keys>=0.4.0:../../finance/py-eth-keys
DEPENDS+=	${PYPKGPREFIX}-eth-rlp>=0.3.0:../../finance/py-eth-rlp
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-hexbytes>=0.1.0:../../devel/py-hexbytes
DEPENDS+=	${PYPKGPREFIX}-rlp>=1.0.0:../../devel/py-rlp
TEST_DEPENDS+=	node-[0-9]*:../../lang/nodejs
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.18.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
