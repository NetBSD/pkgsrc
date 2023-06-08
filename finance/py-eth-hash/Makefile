# $NetBSD: Makefile,v 1.12 2023/06/08 10:23:14 adam Exp $

DISTNAME=	eth-hash-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-hash/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-hash
COMMENT=	Ethereum keccak256 hashing function
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.6.6:../../security/py-cryptodome
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
