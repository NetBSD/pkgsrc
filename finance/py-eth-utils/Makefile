# $NetBSD: Makefile,v 1.13 2024/01/11 10:04:32 adam Exp $

DISTNAME=	eth-utils-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-utils/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-utils
COMMENT=	Common utility functions for ethereum codebases
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cytoolz>=0.10.1:../../devel/py-cytoolz
DEPENDS+=	${PYPKGPREFIX}-eth-hash>=0.3.1:../../finance/py-eth-hash
DEPENDS+=	${PYPKGPREFIX}-eth-typing>=3.0.0:../../finance/py-eth-typing
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=4.43.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.971:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-types-setuptools-[0-9]*:../../devel/py-types-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
