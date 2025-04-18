# $NetBSD: Makefile,v 1.1 2025/04/18 12:46:57 adam Exp $

DISTNAME=	py_ecc-8.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py_//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-ecc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/py_ecc
COMMENT=	Elliptic curve crypto in python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-eth-typing>=3.0.0:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
