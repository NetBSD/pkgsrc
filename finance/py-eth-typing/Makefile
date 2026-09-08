# $NetBSD: Makefile,v 1.22 2026/09/08 08:19:24 adam Exp $

DISTNAME=	eth_typing-6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eth-typing/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-typing
COMMENT=	Common type annotations for ethereum python packages
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
