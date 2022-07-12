# $NetBSD: Makefile,v 1.3 2022/07/12 07:31:17 adam Exp $

DISTNAME=	eth-keys-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-keys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-keys
COMMENT=	Common API for Ethereum key operations
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-eth-typing>=3.0.0:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
