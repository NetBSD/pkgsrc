# $NetBSD: Makefile,v 1.22 2026/03/26 14:41:12 wiz Exp $

DISTNAME=	pygls-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openlawlibrary/pygls
COMMENT=	Pythonic generic implementation of the Language Server Protocol
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-cattrs>=23.1.2:../../devel/py-cattrs
DEPENDS+=	${PYPKGPREFIX}-lsprotocol>=2023.0.1:../../lang/py-lsprotocol
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.21.0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
