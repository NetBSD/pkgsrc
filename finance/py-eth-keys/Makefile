# $NetBSD: Makefile,v 1.14 2026/09/08 11:12:57 adam Exp $

DISTNAME=	eth_keys-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-keys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/eth-keys
COMMENT=	Common API for Ethereum key operations
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-eth-typing>=3:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2:../../finance/py-eth-utils
# TODO: import
#TEST_DEPENDS+=	${PYPKGPREFIX}-asn1tools>=0.146.2
TEST_DEPENDS+=	${PYPKGPREFIX}-asn1>=0.4.5:../../security/py-asn1
TEST_DEPENDS+=	${PYPKGPREFIX}-eth-hash>=0:../../finance/py-eth-hash
TEST_DEPENDS+=	${PYPKGPREFIX}-factory_boy>=3.0.1:../../devel/py-factory_boy
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.10.3:../../devel/py-hypothesis

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
