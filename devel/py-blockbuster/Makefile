# $NetBSD: Makefile,v 1.2 2026/09/29 08:17:33 adam Exp $

DISTNAME=	blockbuster-1.5.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blockbuster/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cbornet/blockbuster
COMMENT=	Utility to detect blocking calls in the async event loop
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-forbiddenfruit>=0.1.4:../../misc/py-forbiddenfruit
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.3:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=1.4.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7.1.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
