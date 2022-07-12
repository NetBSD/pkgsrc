# $NetBSD: Makefile,v 1.8 2022/07/12 07:37:53 adam Exp $

DISTNAME=	eth-account-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-account/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-account
COMMENT=	Sign Ethereum transactions and messages with local private keys
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-bitarray>=1.2.1:../../devel/py-bitarray
DEPENDS+=	${PYPKGPREFIX}-eth-abi>=3.0.0:../../finance/py-eth-abi
DEPENDS+=	${PYPKGPREFIX}-eth-keyfile>=0.6.0:../../finance/py-eth-keyfile
DEPENDS+=	${PYPKGPREFIX}-eth-keys>=0.4.0:../../finance/py-eth-keys
DEPENDS+=	${PYPKGPREFIX}-eth-rlp>=0.3.0:../../finance/py-eth-rlp
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-hexbytes>=0.1.0:../../devel/py-hexbytes
DEPENDS+=	${PYPKGPREFIX}-rlp>=1.0.0:../../devel/py-rlp

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
