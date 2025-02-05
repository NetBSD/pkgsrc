# $NetBSD: Makefile,v 1.19 2025/02/05 19:53:12 adam Exp $

DISTNAME=	rlp-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rlp/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/pyrlp
COMMENT=	Package for Recursive Length Prefix encoding and decoding
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.19.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
