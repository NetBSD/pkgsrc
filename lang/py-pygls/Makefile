# $NetBSD: Makefile,v 1.17 2024/02/06 21:45:58 adam Exp $

DISTNAME=	pygls-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openlawlibrary/pygls
COMMENT=	Pythonic generic implementation of the Language Server Protocol
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-cattrs>=23.1.2:../../devel/py-cattrs
DEPENDS+=	${PYPKGPREFIX}-lsprotocol>=2023.0.1:../../lang/py-lsprotocol
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.21.0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
