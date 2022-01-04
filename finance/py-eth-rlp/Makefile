# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:53 wiz Exp $

DISTNAME=	eth-rlp-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-rlp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-rlp
COMMENT=	RLP definitions for common Ethereum objects in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-eth-utils>=1.0.1:../../finance/py-eth-utils
DEPENDS+=	${PYPKGPREFIX}-hexbytes>=0.1.0:../../devel/py-hexbytes
DEPENDS+=	${PYPKGPREFIX}-rlp>=0.6.0:../../devel/py-rlp

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
