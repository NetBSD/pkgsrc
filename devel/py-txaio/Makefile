# $NetBSD: Makefile,v 1.22 2026/06/28 15:23:39 adam Exp $

DISTNAME=	txaio-26.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txaio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crossbario/txaio
COMMENT=	Compatibility API between asyncio/Twisted/Trollius
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=22.10.0:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
