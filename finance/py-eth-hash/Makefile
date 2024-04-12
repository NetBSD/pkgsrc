# $NetBSD: Makefile,v 1.14 2024/04/12 11:28:56 adam Exp $

DISTNAME=	eth-hash-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-hash/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-hash
COMMENT=	Ethereum keccak256 hashing function
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
# pycryptodome
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.6.6:../../security/py-cryptodome
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
