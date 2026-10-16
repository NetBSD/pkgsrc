# $NetBSD: Makefile,v 1.16 2026/10/16 19:43:54 adam Exp $

DISTNAME=	eth_rlp-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-rlp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-rlp
COMMENT=	RLP definitions for common Ethereum objects in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-hexbytes>=1.2.0:../../devel/py-hexbytes
DEPENDS+=	${PYPKGPREFIX}-rlp>=3.0.0:../../devel/py-rlp
TEST_DEPENDS+=	${PYPKGPREFIX}-eth-hash>=0:../../finance/py-eth-hash
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
