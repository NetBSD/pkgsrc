# $NetBSD: Makefile,v 1.1 2026/10/09 09:12:54 adam Exp $

DISTNAME=	aiothreads-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiothreads/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mosquito/aiothreads
COMMENT=	Glue between async and thread worlds
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-async-timeout>=5.0.1:../../devel/py-async-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=1.1.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6.2.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-plugins>=3.2.0:../../devel/py-test-mypy-plugins

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
