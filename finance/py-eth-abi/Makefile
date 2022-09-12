# $NetBSD: Makefile,v 1.6 2022/09/12 10:57:49 adam Exp $

DISTNAME=	eth_abi-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-abi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-abi
COMMENT=	Python utilities for working with Ethereum ABI definitions
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-eth-typing>=3.0.0:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-parsimonious>=0.8.0:../../textproc/py-parsimonious

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
