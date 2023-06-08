# $NetBSD: Makefile,v 1.10 2023/06/08 10:26:04 adam Exp $

DISTNAME=	eth-utils-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-utils/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-utils
COMMENT=	Common utility functions for ethereum codebases
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cytoolz>=0.10.1:../../devel/py-cytoolz
DEPENDS+=	${PYPKGPREFIX}-eth-hash>=0.3.1:../../finance/py-eth-hash
DEPENDS+=	${PYPKGPREFIX}-eth-typing>=3.0.0:../../finance/py-eth-typing
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.43.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
