# $NetBSD: Makefile,v 1.4 2022/11/14 14:34:49 wiz Exp $

DISTNAME=	eth-keyfile-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-keyfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-keyfile
COMMENT=	Library for handling the encrypted keyfiles
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.6.6:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-eth-keys>=0.4.0:../../finance/py-eth-keys
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 311

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
