# $NetBSD: Makefile,v 1.12 2026/10/16 19:43:42 adam Exp $

DISTNAME=	cleo-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cleo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-poetry/cleo
COMMENT=	Create beautiful and testable command-line interfaces
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-crashtest>=0.4.1:../../misc/py-crashtest
DEPENDS+=	${PYPKGPREFIX}-rapidfuzz>=2.2.0:../../textproc/py-rapidfuzz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
