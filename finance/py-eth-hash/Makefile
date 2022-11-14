# $NetBSD: Makefile,v 1.10 2022/11/14 14:34:49 wiz Exp $

DISTNAME=	eth-hash-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-hash/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-hash
COMMENT=	Ethereum keccak256 hashing function
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.6.6:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-pysha3>=1.0.0:../../devel/py-pysha3
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=3.14.6:../../devel/py-tox

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 311

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
