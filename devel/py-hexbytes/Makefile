# $NetBSD: Makefile,v 1.14 2025/04/12 11:08:23 adam Exp $

DISTNAME=	hexbytes-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hexbytes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/hexbytes
COMMENT=	Python bytes subclass that decodes hex
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-eth-utils>=2.0.0:../../finance/py-eth-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=3.44.24:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
