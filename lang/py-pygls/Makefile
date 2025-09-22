# $NetBSD: Makefile,v 1.19 2025/09/22 07:46:56 wiz Exp $

DISTNAME=	pygls-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
