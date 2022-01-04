# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:53 wiz Exp $

DISTNAME=	eth-keys-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-keys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-keys
COMMENT=	Common API for Ethereum key operations
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-eth-typing>=2.2.1:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=1.3.0:../../finance/py-eth-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
