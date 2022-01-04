# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:53 wiz Exp $

DISTNAME=	eth-keyfile-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-keyfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-keyfile
COMMENT=	Library for handling the encrypted keyfiles
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.4.7:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-cytoolz>=0.9.0:../../devel/py-cytoolz
DEPENDS+=	${PYPKGPREFIX}-eth-keys>=0.1.0:../../finance/py-eth-keys
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=1.0.0:../../finance/py-eth-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
