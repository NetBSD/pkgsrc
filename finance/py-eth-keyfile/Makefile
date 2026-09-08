# $NetBSD: Makefile,v 1.14 2026/09/08 11:14:59 adam Exp $

DISTNAME=	eth_keyfile-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-keyfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-keyfile
COMMENT=	Library for handling the encrypted keyfiles
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.6.6:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-ecc>=5.2.0:../../security/py-ecc
DEPENDS+=	${PYPKGPREFIX}-eth-keys>=0.8.0:../../finance/py-eth-keys
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2:../../finance/py-eth-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
