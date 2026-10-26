# $NetBSD: Makefile,v 1.23 2026/10/26 05:47:17 adam Exp $

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

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
