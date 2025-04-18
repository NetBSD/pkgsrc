# $NetBSD: Makefile,v 1.19 2025/04/18 12:10:16 adam Exp $

DISTNAME=	eth_utils-5.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-utils/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-utils
COMMENT=	Common utility functions for ethereum codebases
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cytoolz>=0.10.1:../../devel/py-cytoolz
DEPENDS+=	${PYPKGPREFIX}-eth-hash>=0.3.1:../../finance/py-eth-hash
DEPENDS+=	${PYPKGPREFIX}-eth-typing>=5.0.0:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.0.0:../../devel/py-pydantic
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.43.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.971:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
