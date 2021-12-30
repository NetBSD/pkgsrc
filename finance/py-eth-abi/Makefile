# $NetBSD: Makefile,v 1.3 2021/12/30 13:05:32 adam Exp $

DISTNAME=	eth_abi-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-abi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-abi
COMMENT=	Python utilities for working with Ethereum ABI definitions
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-eth-typing>=2.0.0:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=1.2.0:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-parsimonious>=0.8.0:../../textproc/py-parsimonious

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
