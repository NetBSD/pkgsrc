# $NetBSD: Makefile,v 1.19 2026/11/02 10:21:43 adam Exp $

DISTNAME=	eth_account-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-account/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-account
COMMENT=	Sign Ethereum transactions and messages with local private keys
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-bitarray>=2.4.0:../../devel/py-bitarray
DEPENDS+=	${PYPKGPREFIX}-ckzg>=2:../../finance/py-ckzg
DEPENDS+=	${PYPKGPREFIX}-eth-abi>=4:../../finance/py-eth-abi
DEPENDS+=	${PYPKGPREFIX}-eth-keyfile>=0.10:../../finance/py-eth-keyfile
DEPENDS+=	${PYPKGPREFIX}-eth-keys>=0.5:../../finance/py-eth-keys
DEPENDS+=	${PYPKGPREFIX}-eth-rlp>=3:../../finance/py-eth-rlp
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=6:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-hexbytes>=2:../../devel/py-hexbytes
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-rlp>=2:../../devel/py-rlp
TEST_DEPENDS+=	nodejs>=0:../../lang/nodejs
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.22.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
